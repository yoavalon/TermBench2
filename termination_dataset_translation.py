import os
import re
import json
import time
import requests

# ==========================================
# 1. CONFIGURATION
# ==========================================
OLLAMA_URL = "http://localhost:11434/api/chat"
MODEL = "qwen2.5-coder:14b"
TARGET_DATASET_ROOT = "dataset"

# Target languages and their file extensions
LANGUAGES = {
    "java": ".java",
    "cpp": ".cpp",
    "c": ".c",
    "php": ".php",
    "javascript": ".js",
    "ruby": ".rb",
    "rust": ".rs",
    "typescript": ".ts",
    "swift": ".swift",
    "r": ".R"
}

# ==========================================
# 2. FILE SYSTEM SETUP
# ==========================================
def setup_directories():
    """Ensures each target language directory exists directly inside dataset/."""
    for lang in LANGUAGES.keys():
        lang_path = os.path.join(TARGET_DATASET_ROOT, lang)
        os.makedirs(lang_path, exist_ok=True)

# ==========================================
# 3. LLM COMMUNICATION
# ==========================================
def ask_llm(system_prompt: str, user_prompt: str, temperature=0.2) -> str:
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
        response = requests.post(OLLAMA_URL, json=payload, timeout=120).json()
        return response.get('message', {}).get('content', "").strip()
    except requests.exceptions.RequestException as e:
        return f"ERROR: {e}"

def translate_code(python_code: str, language: str, target_behavior: str, filename: str) -> str:
    class_name = filename.split('.')[0]
    java_instruction = f"For Java, the public class MUST be named `{class_name}` to match the filename." if language == "java" else ""
    
    system_prompt = (
        f"You are an expert polyglot compiler engineer. "
        f"Your task is to translate a Python script into {language}."
    )
    
    user_prompt = f"""
    Translate the following Python script into {language}.
    
    CRITICAL CONSTRAINTS:
    1. HALTING BEHAVIOR: This code is designed to be {target_behavior.upper()}. 
       You MUST preserve the exact logical flow. Do not optimize away infinite loops.
    2. STRUCTURE: Maintain the same variable names and function structures.
    3. EXECUTABILITY: The script must be self-contained and executable. Call the main function at the bottom.
    4. NO COMMENTS: Strip all comments and docstrings.
    5. FORMATTING: Wrap your output in a single ```{language} ... ``` markdown block.
    {java_instruction}
    
    Python Code:
    ```python
    {python_code}
    ```
    """
    
    response = ask_llm(system_prompt, user_prompt)
    
    if response.startswith("ERROR:"):
        return response

    # Extract code from markdown block
    match = re.search(r"```[a-zA-Z]*\n(.*?)```", response, re.DOTALL)
    if match:
        return match.group(1).strip()
    
    if "```" not in response:
        return response.strip()
        
    return "ERROR: Failed to extract code from LLM response."

# ==========================================
# 4. MAIN ORCHESTRATION LOOP
# ==========================================
def main():
    setup_directories()
    print("\n🚀 Starting Sequential Cross-Language Translation...\n")
    
    python_dir = os.path.join(TARGET_DATASET_ROOT, "python")
    if not os.path.exists(python_dir):
        print(f"❌ Error: '{python_dir}' directory does not exist.")
        return

    # Grab all .py files directly inside dataset/python
    python_files = sorted([f for f in os.listdir(python_dir) if f.endswith(".py")])
    
    if not python_files:
        print(f"⚠️ No Python files found in '{python_dir}'.")
        return

    for file in python_files:
        base_name = os.path.splitext(file)[0]
        src_file_path = os.path.join(python_dir, file)
        json_file_path = os.path.join(python_dir, f"{base_name}.json")
        
        # 1. Read Python source
        with open(src_file_path, 'r', encoding='utf-8') as f:
            python_code = f.read()
            
        # 2. Extract target halting behavior from the JSON metadata
        target_behavior = "terminating"
        if os.path.exists(json_file_path):
            with open(json_file_path, 'r', encoding='utf-8') as f:
                metadata = json.load(f)
                target_behavior = metadata.get("label", "terminating")
        else:
            print(f"⚠️ Warning: Metadata file {base_name}.json not found. Defaulting to 'terminating'.")
        
        print(f"\n📄 Processing: {file} [Behavior: {target_behavior.upper()}]")
        
        # 3. Translate to each target language
        for lang, ext in LANGUAGES.items():
            dest_file_path = os.path.join(TARGET_DATASET_ROOT, lang, f"{base_name}{ext}")
            
            # Idempotency check: Skip if file already exists
            if os.path.exists(dest_file_path):
                print(f"  ⏩ [Skipped] {lang.upper()} (Already exists)")
                continue
                
            print(f"  ⚙️ [Translating] -> {lang.upper()}...", end="", flush=True)
            
            translated_code = translate_code(python_code, lang, target_behavior, f"{base_name}{ext}")
            
            if translated_code.startswith("ERROR:"):
                print(f"\n    ❌ Failed: {translated_code}")
            elif translated_code:
                with open(dest_file_path, 'w', encoding='utf-8') as f:
                    f.write(translated_code)
                print(" ✅ Saved")
            else:
                print("\n    ❌ Failed: Empty output from LLM")
            
            time.sleep(0.5)

    print(f"\n🎉 Translation Complete! All datasets are available in './{TARGET_DATASET_ROOT}'")

if __name__ == "__main__":
    main()