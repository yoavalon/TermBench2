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
    "ytick.labelsize": 10,
    "axes.linewidth": 0.8,
    "text.color": "#2c2c2c",
    "axes.labelcolor": "#2c2c2c",
    "xtick.color": "#2c2c2c",
    "ytick.color": "#2c2c2c"
})

# ==========================================
# 2. EXACT DATA (Sorted by AUROC descending)
# ==========================================
data = [
    {"domain": "State Machines for Network Connections", "f1": 0.9178, "auroc": 0.9920},
    {"domain": "Reinforcement Learning Reward Decay", "f1": 0.9130, "auroc": 0.9829},
    {"domain": "Neural Network Forward Pass Matrix Operations", "f1": 0.8702, "auroc": 0.9833},
    {"domain": "Temporal Frame Sequence Tracking", "f1": 0.8898, "auroc": 0.9705},
    {"domain": "Thermodynamic State Simulations", "f1": 0.8929, "auroc": 0.9592},
    {"domain": "Supply Chain Logistics Optimization", "f1": 0.9040, "auroc": 0.9577},
    {"domain": "Genomic Sequence Alignment Algorithms", "f1": 0.9011, "auroc": 0.9571},
    {"domain": "Decentralized Ledger Consensus Mechanics", "f1": 0.8971, "auroc": 0.9561},
    {"domain": "Digital Signal Processing", "f1": 0.8750, "auroc": 0.9438},
    {"domain": "Abstract Syntax Tree Semantic Linting", "f1": 0.8979, "auroc": 0.9428},
    {"domain": "Flight Trajectory and Cruise Altitude Planning", "f1": 0.8802, "auroc": 0.9411},
    {"domain": "Document Parsing and Lexical Tokenization", "f1": 0.8607, "auroc": 0.9391},
    {"domain": "Cryptographic Hashing and Cipher Simulations", "f1": 0.8381, "auroc": 0.9379},
    {"domain": "Biostatistical P-Value Permutations", "f1": 0.8447, "auroc": 0.9369},
    {"domain": "Fluid Dynamics via Cellular Automata", "f1": 0.8905, "auroc": 0.9314},
    {"domain": "Natural Language Processing Vectorization", "f1": 0.8895, "auroc": 0.9286},
    {"domain": "Financial Monte Carlo Option Pricing Models", "f1": 0.9102, "auroc": 0.9156},
    {"domain": "3D Coordinate Geometry Transformations", "f1": 0.7741, "auroc": 0.9081},
    {"domain": "Particle Swarm Optimization Algorithms", "f1": 0.8129, "auroc": 0.8677},
    {"domain": "Graph Traversal and Shortest Path Routing", "f1": 0.7917, "auroc": 0.8667}
]

# Reverse so the highest score appears at the top of the Y-axis
domains = [d["domain"] for d in data][::-1]
f1_scores = [d["f1"] for d in data][::-1]
auroc_scores = [d["auroc"] for d in data][::-1]

# ==========================================
# 3. PLOT GENERATION
# ==========================================
# Taller figure (9, 10) to accommodate 20 labels comfortably
fig, ax = plt.subplots(figsize=(9, 10))
y_pos = np.arange(len(domains))

# Academic color palette
color_auroc = "#2166ac"  # Deep Academic Blue
color_f1 = "#b2182b"     # Crimson Red

# Draw the dumbbell connections
for i in range(len(domains)):
    ax.plot([f1_scores[i], auroc_scores[i]], [y_pos[i], y_pos[i]], 
            color='gray', alpha=0.3, linewidth=2.0, zorder=1)

# Plot the dots
ax.scatter(f1_scores, y_pos, color=color_f1, s=90, label='F1-Score', 
           zorder=2, edgecolors='white', linewidth=1.2)
ax.scatter(auroc_scores, y_pos, color=color_auroc, s=90, label='AUROC', 
           zorder=2, edgecolors='white', linewidth=1.2)

# ==========================================
# 4. MINIMALIST FORMATTING
# ==========================================
ax.set_yticks(y_pos)
ax.set_yticklabels(domains)
ax.set_xlabel("Metric Score")
ax.set_xlim(0.70, 1.02) # Adjusted bounds based on your minimum score

# Remove spines
ax.spines['top'].set_visible(False)
ax.spines['right'].set_visible(False)
ax.spines['left'].set_visible(False)

# Add subtle vertical grid lines
ax.xaxis.grid(True, linestyle='--', alpha=0.5)
ax.set_axisbelow(True)

# Legend placed elegantly at the top
ax.legend(loc='lower left', bbox_to_anchor=(0, 1.01), ncol=2, frameon=False)

# ==========================================
# 5. EXPORT
# ==========================================
output_filename = "domain_metrics_dumbbell.png"
plt.tight_layout()
plt.savefig(output_filename, format='png', bbox_inches='tight', dpi=300)
print(f"✅ Elegant plot saved successfully as {output_filename}")