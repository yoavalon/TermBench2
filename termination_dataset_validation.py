import os
import json
import time
import random
import requests

# ==========================================
# 1. CONFIGURATION
# ==========================================
OLLAMA_URL = "http://localhost:11434/api/chat"
MODEL = "qwen2.5-coder:14b"
TARGET_DATASET_ROOT = "dataset"
REPORT_FILENAME = "validation_error_report.json"

LANGUAGES = {
    "java": ".java", "cpp": ".cpp", "c": ".c", "php": ".php",
    "javascript": ".js", "ruby": ".rb", "rust": ".rs", 
    "typescript": ".ts", "swift": ".swift", "r": ".R"
}

# ==========================================
# 2. LLM COMMUNICATION
# ==========================================
def ask_llm(system_prompt: str, user_prompt: str, temperature=0.1) -> str:
    """Uses low temperature for deterministic evaluation."""
    payload = {
        "model": MODEL,
        "messages": [
            {"role": "system", "content": system_prompt},
            {"role": "user", "content": user_prompt}
        ],
        "temperature": temperature,
        "stream": False
    }
    try:
        response = requests.post(OLLAMA_URL, json=payload, timeout=60).json()
        return response.get('message', {}).get('content', "").strip()
    except requests.exceptions.RequestException as e:
        return f"ERROR: {e}"

def validate_with_llm(python_code: str, translated_code: str, language: str, behavior: str) -> tuple:
    system_prompt = (
        f"You are a strict, expert static analysis tool for {language}. "
        "Your job is to validate translated code. You MUST reply with ONLY "
        "'VALID' or 'INVALID: <reason>'."
    )
    
    user_prompt = f"""
    Evaluate this {language} translation of a Python script. 
    
    TARGET BEHAVIOR: {behavior.upper()}
    
    Python Source:
    ```python
    {python_code}
    ```
    
    {language.upper()} Translation:
    ```
    {translated_code}
    ```
    
    CHECKS:
    1. SYNTAX: Is this valid, compilable/executable {language} code?
    2. SEMANTICS: Does it exactly preserve the logic? If the Python code has an infinite loop, does the {language} code also have an infinite loop? 
    3. COMPLETENESS: Is the code truncated? Does it call the main function?
    
    If it passes all checks, output ONLY 'VALID'.
    If it fails ANY check, output 'INVALID: ' followed by a brief 1-sentence reason.
    """
    
    response = ask_llm(system_prompt, user_prompt)
    if response.startswith("VALID"):
        return True, "VALID"
    else:
        reason = response.replace("INVALID:", "").strip()
        return False, reason

# ==========================================
# 3. VALIDATION LOOP
# ==========================================
def main():
    print(f"\n🔍 Starting Cross-Language Translation Validation (READ-ONLY)...\n")
    python_dir = os.path.join(TARGET_DATASET_ROOT, "python")
    
    if not os.path.exists(python_dir):
        print(f"❌ Error: '{python_dir}' not found.")
        return

    # Grab files and shuffle them randomly instead of sorting
    python_files = [f for f in os.listdir(python_dir) if f.endswith(".py")]
    random.shuffle(python_files)
    
    validation_report = {lang: {"passed": 0, "failed": 0, "errors": {}} for lang in LANGUAGES}

    for file in python_files:
        base_name = os.path.splitext(file)[0]
        src_file_path = os.path.join(python_dir, file)
        json_file_path = os.path.join(python_dir, f"{base_name}.json")
        
        # Load Source and Metadata
        with open(src_file_path, 'r', encoding='utf-8') as f:
            python_code = f.read()
            
        target_behavior = "terminating"
        if os.path.exists(json_file_path):
            with open(json_file_path, 'r', encoding='utf-8') as f:
                metadata = json.load(f)
                target_behavior = metadata.get("label", "terminating")

        print(f"\n📄 Validating translations for: {file}")

        for lang, ext in LANGUAGES.items():
            dest_file_path = os.path.join(TARGET_DATASET_ROOT, lang, f"{base_name}{ext}")
            file_identifier = f"{base_name}{ext}"
            
            if not os.path.exists(dest_file_path):
                print(f"  ⚠️  [{lang.upper()}] Missing file.")
                validation_report[lang]["failed"] += 1
                validation_report[lang]["errors"][file_identifier] = "File is missing."
                continue

            with open(dest_file_path, 'r', encoding='utf-8') as f:
                translated_code = f.read()

            # 1. Heuristic: Emptiness / Truncation Check
            if len(translated_code.strip()) == 0:
                print(f"  ❌ [{lang.upper()}] Failed: File is empty.")
                validation_report[lang]["failed"] += 1
                validation_report[lang]["errors"][file_identifier] = "File is completely empty."
                continue
                
            if len(translated_code) < (len(python_code) * 0.2):
                print(f"  ❌ [{lang.upper()}] Failed: Code is suspiciously short (truncated).")
                validation_report[lang]["failed"] += 1
                validation_report[lang]["errors"][file_identifier] = "Code truncated (less than 20% of source size)."
                continue

            # 2. LLM Evaluation
            print(f"  ⚙️  Checking {lang.upper()}...", end="", flush=True)
            is_valid, reason = validate_with_llm(python_code, translated_code, lang, target_behavior)
            
            if is_valid:
                print(" ✅ Valid")
                validation_report[lang]["passed"] += 1
            else:
                print(f"\n    ❌ Failed: {reason}")
                validation_report[lang]["failed"] += 1
                validation_report[lang]["errors"][file_identifier] = reason
            
            time.sleep(0.3)

    # Output Report to File
    with open(REPORT_FILENAME, "w", encoding="utf-8") as f:
        json.dump(validation_report, f, indent=4)

    # Output Report Summary to Terminal
    print("\n" + "="*40)
    print("📊 VALIDATION REPORT SUMMARY")
    print("="*40)
    for lang, stats in validation_report.items():
        total = stats['passed'] + stats['failed']
        if total > 0:
            pass_rate = (stats['passed'] / total) * 100
            print(f"{lang.upper():<12} | Passed: {stats['passed']:<4} | Failed: {stats['failed']:<4} | Success Rate: {pass_rate:.1f}%")
        
    print(f"\n📝 Detailed error logs saved to: '{REPORT_FILENAME}'")

if __name__ == "__main__":
    main()