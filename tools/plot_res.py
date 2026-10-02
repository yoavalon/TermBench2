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
# 2. EXACT DATA (Sorted by AUROC descending)
# ==========================================
# Values converted from percentages to 0.0-1.0 scale
data = [
    {"category": "Floating-Point Precision", "f1": 0.9412, "auroc": 0.9859},
    {"category": "Boundary Conditions", "f1": 0.9471, "auroc": 0.9824},
    {"category": "Data Mutations", "f1": 0.9191, "auroc": 0.9812},
    {"category": "Mathematical Sequences", "f1": 0.9356, "auroc": 0.9783},
    {"category": "Recursion", "f1": 0.6089, "auroc": 0.8264}
]

# Reverse so the highest score appears at the top of the Y-axis
categories = [d["category"] for d in data][::-1]
f1_scores = [d["f1"] for d in data][::-1]
auroc_scores = [d["auroc"] for d in data][::-1]

# ==========================================
# 3. PLOT GENERATION
# ==========================================
fig, ax = plt.subplots(figsize=(8, 4.5))
y_pos = np.arange(len(categories))

# Academic color palette (Colorblind safe)
color_auroc = "#2166ac"  # Deep Academic Blue
color_f1 = "#b2182b"     # Crimson Red

# Draw the dumbbell connections
for i in range(len(categories)):
    ax.plot([f1_scores[i], auroc_scores[i]], [y_pos[i], y_pos[i]], 
            color='gray', alpha=0.3, linewidth=2.5, zorder=1)

# Plot the dots with white edges for crispness
ax.scatter(f1_scores, y_pos, color=color_f1, s=120, label='F1-Score', 
           zorder=2, edgecolors='white', linewidth=1.5)
ax.scatter(auroc_scores, y_pos, color=color_auroc, s=120, label='AUROC', 
           zorder=2, edgecolors='white', linewidth=1.5)

# ==========================================
# 4. MINIMALIST FORMATTING
# ==========================================
ax.set_yticks(y_pos)
ax.set_yticklabels(categories)
ax.set_xlabel("Metric Score")
ax.set_xlim(0.55, 1.02) 

# Remove unnecessary spines (borders) for a cleaner look
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['left'].set_visible(False) 

# Add subtle vertical grid lines to assist reading values
ax.xaxis.grid(True, linestyle='--', alpha=0.4)
ax.set_axisbelow(True) # Ensure grid is behind the dots

# Place legend cleanly above the plot
ax.legend(loc='lower left', bbox_to_anchor=(0, 1.02), ncol=2, frameon=False)

# ==========================================
# 5. PNG EXPORT
# ==========================================
output_filename = "category_metrics_dumbbell.png"
plt.tight_layout()
plt.savefig(output_filename, format='png', bbox_inches='tight', dpi=300)
print(f"✅ Elegant plot saved successfully as {output_filename}")