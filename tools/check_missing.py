import os

# ==========================================
# 1. CONFIGURATION
# ==========================================
# Matches the configuration in termination_dataset_translation.py
TARGET_DATASET_ROOT = "dataset"
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

# The expected range of sample files
START_SAMPLE = 1
END_SAMPLE = 3000

# ==========================================
# 2. MISSING FILE SCANNER
# ==========================================
def find_missing_translations():
    missing_report = {}
    total_missing = 0
    
    print(f"🔍 Scanning '{TARGET_DATASET_ROOT}/' for missing translations (samples {START_SAMPLE:04d} to {END_SAMPLE:04d})...\n")
    
    for lang, ext in LANGUAGES.items():
        lang_path = os.path.join(TARGET_DATASET_ROOT, lang)
        missing_files = []
        
        # If the language folder hasn't been created at all yet
        if not os.path.exists(lang_path):
            print(f"⚠️  Directory missing: {lang_path}")
            missing_files = [f"sample_{str(i).zfill(4)}{ext}" for i in range(START_SAMPLE, END_SAMPLE + 1)]
        else:
            # Check for each expected file in the range
            for i in range(START_SAMPLE, END_SAMPLE + 1):
                file_name = f"sample_{str(i).zfill(4)}{ext}"
                expected_path = os.path.join(lang_path, file_name)
                
                if not os.path.exists(expected_path):
                    missing_files.append(file_name)
        
        # Record results for this language
        missing_report[lang] = missing_files
        count = len(missing_files)
        total_missing += count
        
        if count == 0:
            print(f"✅ {lang.upper():<10} : Complete (0 missing)")
        else:
            print(f"❌ {lang.upper():<10} : {count} missing files")
            
    print("-" * 45)
    print(f"Total missing files across all languages: {total_missing}")
    
    # Write the detailed list to a log file if there are any missing
    if total_missing > 0:
        log_filename = "missing_translations_report.txt"
        with open(log_filename, "w", encoding='utf-8') as log:
            log.write(f"Missing Translations Report\n")
            log.write(f"Total Missing: {total_missing}\n")
            log.write("="*30 + "\n\n")
            
            for lang, files in missing_report.items():
                if files:
                    log.write(f"--- {lang.upper()} ({len(files)} missing) ---\n")
                    for f in files:
                        log.write(f"{f}\n")
                    log.write("\n")
                    
        print(f"\n📝 Detailed list of missing files written to '{log_filename}'")

if __name__ == "__main__":
    find_missing_translations()