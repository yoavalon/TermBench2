import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np

# ==========================================
# 1. HARDCODED DATA FROM EVALUATION LOGS
# ==========================================
categories_data = {
    "Category": ["Boundary Conditions", "Floating Point", "Math Sequences", "Data Mutations", "Recursion"],
    "F1": [0.947, 0.941, 0.935, 0.919, 0.608],
    "Accuracy": [0.947, 0.941, 0.935, 0.919, 0.633]
}

length_data = {
    "Length": ["Short\n(<15 lines)", "Medium\n(15-30 lines)", "Long\n(>30 lines)"],
    "F1": [0.911, 0.919, 0.785],
    "Accuracy": [0.911, 0.920, 0.786]
}

domains_data = {
    "Domain": [
        "State Machines for Network Conn.", "Reinforcement Learning Decay", "Financial Monte Carlo",
        "Supply Chain Logistics", "Genomic Sequence Alignment", "AST Semantic Linting",
        "Decentralized Ledger Consensus", "Thermodynamic State", "Fluid Dynamics via Automata",
        "NLP Vectorization", "Temporal Frame Tracking", "Flight Trajectory Planning",
        "Digital Signal Processing", "NN Forward Pass Matrices", "Document Parsing & Lexical",
        "Biostatistical P-Value", "Cryptographic Hashing", "Particle Swarm Optimization",
        "Graph Traversal & Routing", "3D Coordinate Geometry"
    ],
    "F1": [
        0.917, 0.913, 0.910, 0.904, 0.901, 0.897, 0.897, 0.892, 0.890, 0.889,
        0.889, 0.880, 0.875, 0.870, 0.860, 0.844, 0.838, 0.812, 0.791, 0.774
    ]
}

df_cat = pd.DataFrame(categories_data)
df_len = pd.DataFrame(length_data)
df_dom = pd.DataFrame(domains_data).sort_values(by="F1", ascending=True)

# ==========================================
# 2. PLOTTING SETUP
# ==========================================
plt.rcParams.update({
    "font.family": "serif",
    "axes.titlesize": 13,
    "axes.labelsize": 11,
    "xtick.labelsize": 10,
    "ytick.labelsize": 10,
    "figure.dpi": 300,
    "axes.grid": True,
    "grid.alpha": 0.3,
    "grid.linestyle": "--"
})

fig = plt.figure(figsize=(14, 10))
gs = fig.add_gridspec(2, 2, height_ratios=[1, 1.2], hspace=0.35, wspace=0.25)

# --- PANEL A: Category Performance (Lollipop Chart) ---
ax1 = fig.add_subplot(gs[0, 0])
colors = ["#e41a1c" if cat == "Recursion" else "#377eb8" for cat in df_cat["Category"]]

ax1.hlines(y=df_cat["Category"], xmin=0.5, xmax=df_cat["F1"], color=colors, alpha=0.6, linewidth=3)
ax1.scatter(df_cat["F1"], df_cat["Category"], color=colors, s=100, zorder=3)

ax1.set_xlim(0.5, 1.0)
ax1.set_title("(A) Transformer Vulnerability: Impact of Category", loc="left", fontweight="bold")
ax1.set_xlabel("F1-Score")
sns.despine(ax=ax1, left=True, bottom=True)

# --- PANEL B: Length Degradation (Line Plot) ---
ax2 = fig.add_subplot(gs[0, 1])
ax2.plot(df_len["Length"], df_len["F1"], marker='o', markersize=9, color="#4daf4a", linewidth=2.5, label="F1-Score")
ax2.plot(df_len["Length"], df_len["Accuracy"], marker='s', markersize=8, color="#984ea3", linewidth=2.5, linestyle="--", label="Accuracy")

ax2.set_ylim(0.5, 1.0)
ax2.set_title("(B) Context Decay: Impact of Code Length", loc="left", fontweight="bold")
ax2.set_ylabel("Score")
ax2.legend(loc="lower left", frameon=True)
sns.despine(ax=ax2, top=True, right=True)

# --- PANEL C: Domain Variance (Dot Plot) ---
ax3 = fig.add_subplot(gs[1, :])
ax3.scatter(df_dom["F1"], df_dom["Domain"], color="#ff7f00", s=70, alpha=0.8, zorder=3)

# Highlight median
median_f1 = df_dom["F1"].median()
ax3.axvline(median_f1, color="gray", linestyle="--", linewidth=1.5, zorder=1, label=f"Median F1 ({median_f1:.3f})")

ax3.set_xlim(0.7, 0.95)
ax3.set_title("(C) Semantic Domain Generalization Map", loc="left", fontweight="bold")
ax3.set_xlabel("F1-Score")
ax3.legend(loc="lower right")
sns.despine(ax=ax3, left=True, bottom=True)

# ==========================================
# 3. EXPORT
# ==========================================
output_path = "termbench_evaluation_map.pdf"
plt.savefig(output_path, bbox_inches="tight", dpi=300)
print(f"✅ Evaluation map successfully saved to {output_path}")