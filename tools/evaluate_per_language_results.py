import os
import glob
import json
import re
#import matplotlib.subplots
import matplotlib.pyplot as plt
import numpy as np

# ==========================================
# 1. ACADEMIC STYLING CONFIGURATION
# ==========================================
plt.rcParams.update({
    "font.family": "serif",
    "font.size": 11,
    "axes.labelsize": 12,
    "legend.fontsize": 11,
    "xtick.labelsize": 10,
    "ytick.labelsize": 11,
    "axes.linewidth": 0.8,
    "text.color": "#2c2c2c",
    "axes.labelcolor": "#2c2c2c",
    "xtick.color": "#2c2c2c",
    "ytick.color": "#2c2c2c"
})

# ==========================================
# 2. RESULT FILE PARSER
# ==========================================
def parse_results_files(directory="."):
    """Parses overall F1 and AUROC metrics from all results_*.txt files."""
    parsed_data = []
    file_pattern = os.path.join(directory, "results_*.txt")
    files = glob.glob(file_pattern)
    
    for file in files:
        # Extract language name from filename (e.g., results_cpp.txt -> Cpp)
        lang_name = os.path.basename(file).replace("results_", "").replace(".txt", "").capitalize()
        
        # Handle specific capitalization formatting
        if lang_name.lower() == "cpp": lang_name = "C++"
        if lang_name.lower() == "php": lang_name = "PHP"
        
        with open(file, "r", encoding="utf-8") as f:
            content = f.read()
            
        # Regex to extract the JSON dictionary under OVERALL TEST METRICS
        match = re.search(r"--- OVERALL TEST METRICS ---\n(.*?)\n\n--- METRICS PER CATEGORY ---", content, re.DOTALL)
        
        if match:
            try:
                metrics = json.loads(match.group(1).strip())
                parsed_data.append({
                    "language": lang_name,
                    "f1": metrics.get("overall_f1", 0.0),
                    "auroc": metrics.get("overall_auroc_prob", 0.0)
                })
            except json.JSONDecodeError:
                print(f"⚠️ Could not parse JSON in {file}")
                
    return parsed_data

# ==========================================
# 3. DATA PREPARATION
# ==========================================
data = parse_results_files()

# Fallback: If no files are found (e.g., testing the script before training finishes), use mock data.
if not data:
    print("⚠️ No 'results_*.txt' files found in the current directory. Using mocked data for preview.")
    data = [
        {"language": "Python", "f1": 0.941, "auroc": 0.985},
        {"language": "Java", "f1": 0.925, "auroc": 0.978},
        {"language": "C++", "f1": 0.891, "auroc": 0.952},
        {"language": "Rust", "f1": 0.932, "auroc": 0.981},
        {"language": "JavaScript", "f1": 0.864, "auroc": 0.921},
        {"language": "TypeScript", "f1": 0.880, "auroc": 0.935},
        {"language": "Swift", "f1": 0.910, "auroc": 0.966},
        {"language": "C", "f1": 0.855, "auroc": 0.910},
        {"language": "PHP", "f1": 0.820, "auroc": 0.885},
        {"language": "Ruby", "f1": 0.845, "auroc": 0.902},
        {"language": "R", "f1": 0.810, "auroc": 0.875}
    ]

# Sort languages by AUROC descending for a clean visual hierarchy
data.sort(key=lambda x: x["auroc"], reverse=False) # False so highest is at the top of the Y-axis

languages = [d["language"] for d in data]
f1_scores = [d["f1"] for d in data]
auroc_scores = [d["auroc"] for d in data]

# ==========================================
# 4. PLOT GENERATION
# ==========================================
# Adjust height dynamically based on the number of languages found
fig_height = max(4, len(languages) * 0.45)
fig, ax = plt.subplots(figsize=(8, fig_height))
y_pos = np.arange(len(languages))

color_auroc = "#2166ac"  # Deep Academic Blue
color_f1 = "#b2182b"     # Crimson Red

# Draw the dumbbell connecting lines
for i in range(len(languages)):
    ax.plot([f1_scores[i], auroc_scores[i]], [y_pos[i], y_pos[i]], 
            color='gray', alpha=0.3, linewidth=2.0, zorder=1)

# Plot the metric dots
ax.scatter(f1_scores, y_pos, color=color_f1, s=90, label='F1-Score', 
           zorder=2, edgecolors='white', linewidth=1.2)
ax.scatter(auroc_scores, y_pos, color=color_auroc, s=90, label='AUROC', 
           zorder=2, edgecolors='white', linewidth=1.2)

# ==========================================
# 5. MINIMALIST FORMATTING
# ==========================================
ax.set_yticks(y_pos)
ax.set_yticklabels(languages)
ax.set_xlabel("Overall Metric Score")

# Dynamically set X-axis limits based on data minimums for tight scaling
min_score = min(min(f1_scores), min(auroc_scores))
ax.set_xlim(max(0.0, min_score - 0.05), 1.02)

ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['left'].set_visible(False)

ax.xaxis.grid(True, linestyle='--', alpha=0.5)
ax.set_axisbelow(True)

ax.legend(loc='lower left', bbox_to_anchor=(0, 1.01), ncol=2, frameon=False)

# ==========================================
# 6. EXPORT
# ==========================================
output_filename = "overall_language_metrics_dumbbell.png"
plt.tight_layout()
plt.savefig(output_filename, format='png', bbox_inches='tight', dpi=300)
print(f"✅ Language parsing complete. Plot saved as {output_filename}")