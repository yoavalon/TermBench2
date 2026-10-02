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
            "ast_nodes": meta.get("ast_nodes", 0)
        })

    random.seed(seed)
    random.shuffle(all_samples)
    
    split_idx = int(len(all_samples) * (1 - test_size))
    #test_samples = all_samples[split_idx:]
    test_samples = all_samples
    
    print(f"Reconstructed Test Set: {len(test_samples)} samples.")

    test_data = {k: [d[k] for d in test_samples] for k in test_samples[0].keys()}
    return Dataset.from_dict(test_data)

# ==========================================
# 3. LOAD MODEL & TOKENIZER
# ==========================================
print(f"Loading model from checkpoint: {CHECKPOINT_PATH}")

tokenizer = AutoTokenizer.from_pretrained(BASE_MODEL)
model = AutoModelForSequenceClassification.from_pretrained(CHECKPOINT_PATH)

test_ds_raw = load_test_dataset_only()

def preprocess_function(examples):
    return tokenizer(examples["text"], truncation=True, max_length=512)

print("Tokenizing test data...")
test_ds = test_ds_raw.map(preprocess_function, batched=True)
data_collator = DataCollatorWithPadding(tokenizer=tokenizer)

training_args = TrainingArguments(
    output_dir="./tmp_eval",
    per_device_eval_batch_size=8,
    report_to="none"
)

trainer = Trainer(
    model=model,
    args=training_args,
    processing_class=tokenizer,
    data_collator=data_collator,
)

# ==========================================
# 4. PREDICT & STATISTICAL ANALYSIS
# ==========================================
print("\n--- Running Predictions ---")
predictions_output = trainer.predict(test_ds)
preds = np.argmax(predictions_output.predictions, axis=-1)
labels = predictions_output.label_ids
ast_counts = test_ds["ast_nodes"]

print("\n--- Generating Scientific AST Complexity Plot ---")

df_results = pd.DataFrame({
    "AST_Nodes": ast_counts,
    "True_Label": labels,
    "Prediction": preds
})

df_results["Correct"] = (df_results["True_Label"] == df_results["Prediction"]).astype(int)
df_results["AST_Bin"] = pd.qcut(df_results["AST_Nodes"], q=10, duplicates="drop")

# Calculate Mean, Accuracy, and Sample Count per bin
bin_stats = df_results.groupby("AST_Bin", observed=True).agg(
    Mean_AST=("AST_Nodes", "mean"),
    Accuracy=("Correct", "mean"),
    Count=("Correct", "count")
).reset_index()

# Calculate 95% Confidence Interval for a proportion
bin_stats["CI_95"] = 1.96 * np.sqrt((bin_stats["Accuracy"] * (1 - bin_stats["Accuracy"])) / bin_stats["Count"])

# Create evenly spaced X-axis indices (1 through 10)
bin_stats["Bin_Index"] = np.arange(1, len(bin_stats) + 1)
# Create clean labels for the x-axis ticks based on the actual AST means
bin_stats["X_Labels"] = bin_stats["Mean_AST"].round().astype(int).astype(str)

# ==========================================
# 5. SCIENTIFIC PLOTTING
# ==========================================
plt.rcParams.update({
    "font.family": "serif",
    "axes.labelsize": 12,
    "axes.titlesize": 14,
    "figure.dpi": 300,
    "axes.grid": True,
    "grid.alpha": 0.4,
    "grid.linestyle": "--"
})

plt.figure(figsize=(10, 6.5))

# Elegant, understated scientific palette
line_color = "#2c3e50"   # Deep Slate Navy
error_color = "#7f8c8d"  # Steel Gray

# Plot evenly spaced points with mathematical error bars
plt.errorbar(
    x=bin_stats["Bin_Index"],
    y=bin_stats["Accuracy"],
    yerr=bin_stats["CI_95"],
    fmt='-s',               # Square markers for a more formal look
    color=line_color,
    linewidth=2,
    capsize=5,
    capthick=1.5,
    ecolor=error_color,
    markersize=7,
    markerfacecolor="#ffffff",
    markeredgewidth=1.5,
    label="Mean Accuracy ± 95% CI"
)

plt.title("Transformer Degradation: Accuracy vs. Structural Complexity", loc="left", pad=15, fontweight="bold")
plt.xlabel("Structural Complexity Deciles (Mean AST Nodes per Bin)")
plt.ylabel("Prediction Accuracy")

# Set X-axis to display the evenly spaced integers, but label them with the AST node counts
plt.xticks(ticks=bin_stats["Bin_Index"], labels=bin_stats["X_Labels"])

# Set Y-axis limits and ticks
plt.ylim(0.4, 1.05)
plt.yticks(np.arange(0.4, 1.1, 0.1))

plt.legend(loc="lower left", frameon=True, edgecolor="black")
sns.despine(top=True, right=True)
plt.tight_layout()

output_file = "ast_complexity_vs_accuracy.png"
plt.savefig(output_file, bbox_inches="tight", dpi=300)
print(f"✅ Scientific AST Complexity plot saved to: {output_file}")