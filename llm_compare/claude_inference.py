import os
import glob
import json
import random
import time
import subprocess
import pandas as pd
from tqdm import tqdm
from sklearn.metrics import accuracy_score

# ==========================================
# CONFIGURATION
# ==========================================
DATASET_ROOT = "dataset"
OUTPUT_CSV = "termination_results_claude-sonnet-5-5.csv"
RANDOM_SEED = 42
SAMPLES_PER_LANG = 60

# Use a current Claude model
CLAUDE_MODEL = "claude-sonnet-5-5" 

# 11 Languages and their respective extensions
LANGUAGES = {
    "python": ".py",
    "java": ".java",
    "cpp": ".cpp",
    "c": ".c",
    "php": ".php",
    "javascript": ".js",
    "ruby": ".rb",
    "rust": ".rs",
    "typescript": ".ts",
    "swift": ".swift",
    "r": ".R",
}

# Ensure API key is configured
API_KEY = os.environ.get("ANTHROPIC_API_KEY", "")

# ==========================================
# STRATIFIED SAMPLING
# ==========================================
def select_stratified_sample_ids(dataset_root: str, n_samples: int = 60, seed: int = 42) -> list:
    """
    Selects n_samples base IDs ensuring all categories, lengths,
    and halting labels are represented.
    """
    py_dir = os.path.join(dataset_root, "python")
    json_files = glob.glob(os.path.join(py_dir, "*.json"))
    
    if not json_files:
        raise FileNotFoundError(f"No metadata files found in {py_dir}")

    records = []
    for jf in json_files:
        with open(jf, "r", encoding="utf-8") as f:
            data = json.load(f)
            records.append({
                "id": data["id"],
                "category": data["category"],
                "length": data["length"],
                "label": 1 if data["label"] == "terminating" else 0
            })

    df_meta = pd.DataFrame(records)
    random.seed(seed)

    # 1. Guarantee coverage: pick at least 1 sample for every (category, length) pair (15 slots)
    selected_ids = set()
    grouped = df_meta.groupby(["category", "length"])
    
    for _, group in grouped:
        sampled_id = group.sample(n=1, random_state=seed)["id"].iloc[0]
        selected_ids.add(sampled_id)

    # 2. Fill remaining slots up to n_samples while balancing labels
    remaining = df_meta[~df_meta["id"].isin(selected_ids)]
    needed = n_samples - len(selected_ids)
    if needed > 0:
        fill_samples = remaining.sample(n=needed, random_state=seed)["id"].tolist()
        selected_ids.update(fill_samples)

    final_ids = sorted(list(selected_ids))[:n_samples]
    print(f"Selected {len(final_ids)} canonical samples across all categories and lengths.")
    return final_ids

# ==========================================
# LLM INFERENCE VIA NATIVE CURL & PARSING
# ==========================================
# ==========================================
# LLM INFERENCE VIA NATIVE CURL & PARSING
# ==========================================
def inference(source_code: str, language: str) -> str:
    prompt = (
        f"You are a program analysis engine. Check whether the following {language} "
        "program terminates on all inputs or loops infinitely.\n"
        "Do not provide any explanation, preamble, or markdown.\n"
        f"Respond ONLY with 'yes' if it terminates, or 'no' if it does not terminate:\n\n{source_code}"
    )

    url = "https://api.anthropic.com/v1/messages"
    headers = [
        "-H", f"x-api-key: {API_KEY}",
        "-H", "anthropic-version: 2023-06-01",
        "-H", "content-type: application/json"
    ]

    payload = {
        "model": CLAUDE_MODEL,
        "max_tokens": 10,
        "system": "You are a concise formal verification oracle.",
        "messages": [{"role": "user", "content": prompt}]
    }

    cmd = ["curl", "-s", "-X", "POST", url] + headers + ["-d", json.dumps(payload)]
    
    # Run curl subprocess with a strict 40-second timeout
    result = subprocess.run(cmd, capture_output=True, text=True, timeout=40)
    
    if result.returncode != 0:
        raise RuntimeError(f"Curl command failed with exit code {result.returncode}")

    res_json = json.loads(result.stdout)
    
    # Safely extract text from Anthropic JSON response structure
    if "content" in res_json and len(res_json["content"]) > 0:
        content_block = res_json["content"][0]
        # Handle both dict and object notations safely
        if isinstance(content_block, dict):
            return content_block.get("text", "").strip()
        return str(content_block).strip()
    elif "error" in res_json:
        raise RuntimeError(f"API Error: {res_json['error'].get('message')}")
    else:
        raise RuntimeError(f"Unexpected response format: {result.stdout}")
    
def parse_answer(response_text: str):
    cleaned = response_text.lower().strip()
    if cleaned.startswith("yes"):
        return 1
    elif cleaned.startswith("no"):
        return 0
    return None

# ==========================================
# EXECUTION CONTROLLER
# ==========================================
# ==========================================
# EXECUTION CONTROLLER
# ==========================================
def run_evaluation():
    sample_ids = select_stratified_sample_ids(DATASET_ROOT, n_samples=SAMPLES_PER_LANG, seed=RANDOM_SEED)

    # Resume from existing results if file exists
    completed_keys = set()
    rows_list = []
    
    if os.path.exists(OUTPUT_CSV):
        results_df = pd.read_csv(OUTPUT_CSV)
        completed_keys = set(zip(results_df["sample_id"], results_df["language"]))
        # Load existing rows into our list so we preserve history when appending
        rows_list = results_df.to_dict('records')

    for sample_id in tqdm(sample_ids, desc="Programs"):
        json_path = os.path.join(DATASET_ROOT, "python", f"{sample_id}.json")
        with open(json_path, "r", encoding="utf-8") as f:
            meta = json.load(f)

        ground_truth = 1 if meta["label"] == "terminating" else 0

        for lang, ext in LANGUAGES.items():
            if (sample_id, lang) in completed_keys:
                continue

            file_path = os.path.join(DATASET_ROOT, lang, f"{sample_id}{ext}")
            if not os.path.exists(file_path):
                print(f"Skipping missing file: {file_path}")
                continue

            with open(file_path, "r", encoding="utf-8") as f:
                code = f.read()

            try:
                raw_resp = inference(code, lang)
                pred = parse_answer(raw_resp)
            except Exception as e:
                print(f"API Error on {sample_id} ({lang}): {e}")
                raw_resp = f"ERROR: {e}"
                pred = None

            # Append new record as a standard dictionary
            rows_list.append({
                "sample_id": sample_id,
                "language": lang,
                "category": meta["category"],
                "length": meta["length"],
                "ground_truth": ground_truth,
                "raw_response": raw_resp,
                "prediction": pred
            })

            # Save immediately to CSV using a fresh DataFrame view
            results_df = pd.DataFrame(rows_list)
            results_df.to_csv(OUTPUT_CSV, index=False)

            # Brief pause to keep requests smooth
            time.sleep(0.2)

    # ==========================================
    # SUMMARY REPORT
    # ==========================================
    print("\n--- Evaluation Complete ---")
    results_df = pd.DataFrame(rows_list)
    valid_df = results_df.dropna(subset=["prediction"])
    
    print(f"Valid evaluations: {len(valid_df)} / {len(results_df)}")
    overall_acc = accuracy_score(valid_df["ground_truth"].astype(int), valid_df["prediction"].astype(int))
    print(f"Overall Claude Accuracy: {overall_acc * 100:.2f}%\n")

    print("Accuracy by Language:")
    for lang, group in valid_df.groupby("language"):
        acc = accuracy_score(group["ground_truth"].astype(int), group["prediction"].astype(int))
        print(f"  - {lang:12s}: {acc * 100:.1f}% ({len(group)} samples)")

if __name__ == "__main__":
    run_evaluation()