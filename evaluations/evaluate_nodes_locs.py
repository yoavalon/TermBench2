import os
import glob
import json
import random
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
from datasets import Dataset
from transformers import (
    AutoTokenizer, 
    AutoModelForSequenceClassification, 
    Trainer, 
    TrainingArguments,
    DataCollatorWithPadding
)

# ==========================================
# 1. CONFIGURATION
# ==========================================
CHECKPOINT_PATH = "/home/algo/code/TermBench2/outputs/TermBench/microsoft/codebert-base/checkpoint-225"
BASE_MODEL = "microsoft/codebert-base"
DATASET_ROOT = "dataset"

# ==========================================
# 2. DATASET RECONSTRUCTION
# ==========================================
def load_test_dataset_only(base_dir=DATASET_ROOT, test_size=0.4, seed=42):
    py_dir = os.path.join(base_dir, "python")
    json_files = glob.glob(os.path.join(py_dir, "*.json"))
    
    all_samples = []
    
    for jf in json_files:
        py_file = jf.replace(".json", ".py")
        if not os.path.exists(py_file):
            continue
            
        with open(jf, "r", encoding="utf-8") as f:
            meta = json.load(f)
            
        with open(py_file, "r", encoding="utf-8") as f:
            content = f.read()
            
        label_id = 1 if meta.get("label") == "terminating" else 0
        
        all_samples.append({
            "text": content,
            "label": label_id,
            "ast_nodes": meta.get("ast_nodes", 0),
            "logical_loc": meta.get("logical_loc", 0)
        })

    random.seed(seed)
    random.shuffle(all_samples)
    
    split_idx = int(len(all_samples) * (1 - test_size))
    test_samples = all_samples #[split_idx:]
    
    print(f"Reconstructed Test Set: {len(test_samples)} samples.")

    test_data = {k: [d[k] for d in test_samples] for k in test_samples[0].keys()}
    return Dataset.from_dict(test_data)

# ==========================================
# 3. LOAD MODEL & PREDICT
# ==========================================
print(f"Loading model from checkpoint: {CHECKPOINT_PATH}")

tokenizer = AutoTokenizer.from_pretrained(BASE_MODEL)
model = AutoModelForSequenceClassification.from_pretrained(CHECKPOINT_PATH)
test_ds_raw = load_test_dataset_only()

def preprocess_function(examples):
    return tokenizer(examples["text"], truncation=True, max_length=512)

test_ds = test_ds_raw.map(preprocess_function, batched=True)
data_collator = DataCollatorWithPadding(tokenizer=tokenizer)

trainer = Trainer(
    model=model,
    args=TrainingArguments(output_dir="./tmp_eval", per_device_eval_batch_size=8, report_to="none"),
    processing_class=tokenizer,
    data_collator=data_collator,
)

print("\n--- Running Predictions ---")
predictions_output = trainer.predict(test_ds)
preds = np.argmax(predictions_output.predictions, axis=-1)
labels = predictions_output.label_ids

df_results = pd.DataFrame({
    "AST_Nodes": test_ds["ast_nodes"],
    "LOC": test_ds["logical_loc"],
    "True_Label": labels,
    "Prediction": preds
})

df_results["Correct"] = (df_results["True_Label"] == df_results["Prediction"]).astype(int)

# ==========================================
# 4. STATISTICAL BINNING
# ==========================================
df_results["AST_Bin"] = pd.qcut(df_results["AST_Nodes"], q=10, duplicates="drop")
ast_stats = df_results.groupby("AST_Bin", observed=True).agg(
    Mean_Val=("AST_Nodes", "mean"), Accuracy=("Correct", "mean"), Count=("Correct", "count")
).reset_index()
ast_stats["CI_95"] = 1.96 * np.sqrt((ast_stats["Accuracy"] * (1 - ast_stats["Accuracy"])) / ast_stats["Count"])

df_results["LOC_Bin"] = pd.qcut(df_results["LOC"], q=10, duplicates="drop")
loc_stats = df_results.groupby("LOC_Bin", observed=True).agg(
    Mean_Val=("LOC", "mean"), Accuracy=("Correct", "mean"), Count=("Correct", "count")
).reset_index()
loc_stats["CI_95"] = 1.96 * np.sqrt((loc_stats["Accuracy"] * (1 - loc_stats["Accuracy"])) / loc_stats["Count"])

# ==========================================
# 5. ELEGANT DUAL X-AXIS PLOTTING
# ==========================================
print("\n--- Generating Elegant Complexity Plot ---")

plt.rcParams.update({
    "font.family": "serif",
    "axes.labelsize": 11,
    "axes.titlesize": 12,
    "legend.fontsize": 10,
    "xtick.labelsize": 10,
    "ytick.labelsize": 10,
    "figure.dpi": 300,
    "axes.linewidth": 1.2,       # Thicker, robust bounding box
})

# Narrower, more traditional scientific aspect ratio
fig, ax1 = plt.subplots(figsize=(7.5, 6))

color_loc = "#900C3F"  # Muted deep red
color_ast = "#1f77b4"  # Traditional steel blue

# --- BOTTOM AXIS (Lines of Code) ---
ax1.set_xlabel("Mean Lines of Code (LOC)", color="black", labelpad=10)
ax1.set_ylabel("Prediction Accuracy", color="black", labelpad=10)
ax1.tick_params(axis='x', colors='black', direction='in', length=5)
ax1.tick_params(axis='y', colors='black', direction='in', length=5)

ax1.set_ylim(0.4, 1.05)
ax1.set_yticks(np.arange(0.4, 1.1, 0.1))

# Horizontal grid only, very subtle
ax1.yaxis.grid(True, linestyle='--', alpha=0.4, color='gray')
ax1.xaxis.grid(False)

line1 = ax1.errorbar(
    x=loc_stats["Mean_Val"], 
    y=loc_stats["Accuracy"], 
    yerr=loc_stats["CI_95"],
    fmt='--s',               # Dashed line with squares for LOC
    color=color_loc, 
    linewidth=2.0, 
    capsize=4, 
    capthick=1.2,
    markersize=6, 
    markerfacecolor="white", 
    markeredgewidth=1.5,
    label="Lines of Code (Bottom Axis)"
)

# --- TOP AXIS (AST Nodes) ---
ax2 = ax1.twiny()  

ax2.set_xlabel("Mean Syntactic Scale (AST Nodes)", color="black", labelpad=10)
ax2.tick_params(axis='x', colors='black', direction='in', length=5)
ax2.xaxis.grid(False)

line2 = ax2.errorbar(
    x=ast_stats["Mean_Val"], 
    y=ast_stats["Accuracy"], 
    yerr=ast_stats["CI_95"],
    fmt='-o',                # Solid line with circles for AST
    color=color_ast, 
    linewidth=2.0, 
    capsize=4, 
    capthick=1.2,
    markersize=6, 
    markerfacecolor="white", 
    markeredgewidth=1.5,
    label="AST Nodes (Top Axis)"
)

plt.title("Transformer Degradation vs. Structural Complexity", pad=20, fontweight="bold")

# --- COMBINED LEGEND ---
lines_1, labels_1 = ax1.get_legend_handles_labels()
lines_2, labels_2 = ax2.get_legend_handles_labels()
ax1.legend(lines_1 + lines_2, labels_1 + labels_2, loc="lower left", frameon=True, edgecolor="black", fancybox=False)

plt.tight_layout()

output_file = "dual_axis_complexity_degradation_elegant.png"
plt.savefig(output_file, bbox_inches="tight", dpi=300)
print(f"✅ Elegant Dual X-Axis plot saved to: {output_file}")