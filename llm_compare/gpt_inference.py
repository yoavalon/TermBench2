import os
import glob
import json
import random
import pandas as pd
from tqdm import tqdm
from openai import OpenAI
from sklearn.metrics import accuracy_score

# ==========================================
# CONFIGURATION
# ==========================================
DATASET_ROOT = "dataset"
OUTPUT_CSV = "termination_results_gpt6_luna.csv"
RANDOM_SEED = 42
SAMPLES_PER_LANG = 60 #20

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

client = OpenAI(api_key=os.environ.get("OPENAI_API_KEY", ''))

# ==========================================
# STRATIFIED SAMPLING
# ==========================================
def select_stratified_sample_ids(dataset_root: str, n_samples: int = 20, seed: int = 42) -> list:
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
# LLM INFERENCE & PARSING
# ==========================================
def inference(source_code: str, language: str) -> str:
    prompt = (
        f"You are a program analysis engine. Check whether the following {language} "
        "program terminates on all inputs or loops infinitely.\n"
        "Do not provide any explanation, preamble, or markdown.\n"
        f"Respond ONLY with 'yes' if it terminates, or 'no' if it does not terminate:\n\n{source_code}"
    )

    response = client.chat.completions.create(
        model="gpt-6-luna",
        #temperature=0.0,
        messages=[
            {"role": "system", "content": "You are a concise formal verification oracle."},
            {"role": "user", "content": prompt}
        ]
    )
    return response.choices[0].message.content.strip()

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
def run_evaluation():
    sample_ids = select_stratified_sample_ids(DATASET_ROOT, n_samples=SAMPLES_PER_LANG, seed=RANDOM_SEED)

    # Resume from existing results if file exists
    if os.path.exists(OUTPUT_CSV):
        results_df = pd.read_csv(OUTPUT_CSV)
        completed_keys = set(zip(results_df["sample_id"], results_df["language"]))
    else:
        results_df = pd.DataFrame(columns=[
            "sample_id", "language", "category", "length", 
            "ground_truth", "raw_response", "prediction"
        ])
        completed_keys = set()

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

            new_row = pd.DataFrame([{
                "sample_id": sample_id,
                "language": lang,
                "category": meta["category"],
                "length": meta["length"],
                "ground_truth": ground_truth,
                "raw_response": raw_resp,
                "prediction": pred
            }])

            results_df = pd.concat([results_df, new_row], ignore_index=True)
            results_df.to_csv(OUTPUT_CSV, index=False)

    # ==========================================
    # SUMMARY REPORT
    # ==========================================
    print("\n--- Evaluation Complete ---")
    valid_df = results_df.dropna(subset=["prediction"])
    
    print(f"Valid evaluations: {len(valid_df)} / {len(results_df)}")
    overall_acc = accuracy_score(valid_df["ground_truth"].astype(int), valid_df["prediction"].astype(int))
    print(f"Overall GPT-4o Accuracy: {overall_acc * 100:.2f}%\n")

    print("Accuracy by Language:")
    for lang, group in valid_df.groupby("language"):
        acc = accuracy_score(group["ground_truth"].astype(int), group["prediction"].astype(int))
        print(f"  - {lang:12s}: {acc * 100:.1f}% ({len(group)} samples)")

if __name__ == "__main__":
    run_evaluation()