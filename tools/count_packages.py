import os
import json
from collections import Counter

# ==========================================
# CONFIGURATION
# ==========================================
DATASET_ROOT = os.path.join("dataset", "python")

def print_counter_stats(title: str, counter: Counter):
    """Helper function to print counter stats neatly."""
    print(f"\n--- {title.upper()} ---")
    if not counter:
        print("  No data found.")
        return
        
    # Sort by count descending, then alphabetically
    sorted_items = sorted(counter.items(), key=lambda x: (-x[1], x[0]))
    for key, count in sorted_items:
        print(f"  {key:<50}: {count}")

def analyze_dataset(directory: str):
    if not os.path.exists(directory):
        print(f"❌ Error: Directory '{directory}' does not exist.")
        return

    # Initialize counters
    categories = Counter()
    domains = Counter()
    lengths = Counter()
    labels = Counter()
    total_files = 0
    error_files = 0

    print(f"📂 Scanning directory: {directory}...")

    # Parse all JSON files
    for filename in os.listdir(directory):
        if filename.endswith(".json"):
            filepath = os.path.join(directory, filename)
            try:
                with open(filepath, 'r', encoding='utf-8') as f:
                    metadata = json.load(f)
                    
                    categories[metadata.get("category", "Unknown")] += 1
                    domains[metadata.get("domain", "Unknown")] += 1
                    lengths[metadata.get("length", "Unknown")] += 1
                    labels[metadata.get("label", "Unknown")] += 1
                    
                    total_files += 1
            except Exception as e:
                print(f"⚠️ Error reading {filename}: {e}")
                error_files += 1

    # Output results
    print(f"\nScan Complete. Successfully parsed {total_files} files.")
    if error_files > 0:
        print(f"⚠️ Failed to parse {error_files} files.")

    print_counter_stats("Labels (Terminating vs Non-Terminating)", labels)
    print_counter_stats("Lengths", lengths)
    print_counter_stats("Categories", categories)
    print_counter_stats("Domains", domains)
    
    print(f"\nTotal valid JSON samples: {total_files}")

if __name__ == "__main__":
    analyze_dataset(DATASET_ROOT)