import os
import sys
import glob
import json
import random
import time
import numpy as np
import evaluate
import torch
import gc
from datasets import Dataset, DatasetDict
from transformers import (
    AutoTokenizer, 
    DataCollatorWithPadding,
    AutoModelForSequenceClassification, 
    TrainingArguments, 
    Trainer
)
from sklearn.metrics import precision_score, recall_score, f1_score, roc_auc_score, average_precision_score

# ==========================================
# 1. CONFIGURATION
# ==========================================
BASE_MODEL = "microsoft/codebert-base"
DATASET_ROOT = "dataset"
TEST_SIZE_SPLIT = 0.4
SEED = 42
GPU_REST_SECONDS = 5.0 # Wait time between languages to free VRAM

# Define target languages based on the translation script outputs
LANGUAGES = [
    "python", "java", "cpp", "c", "php", 
    "javascript", "ruby", "rust", "typescript", "swift", "r"
]

# ==========================================
# 2. CROSS-FOLDER DATASET LOADER (Fault Tolerant)
# ==========================================
def load_cross_language_dataset(language, base_dir=DATASET_ROOT, test_size=TEST_SIZE_SPLIT, seed=SEED):
    """
    Loads whatever code successfully translated into the language folder, 
    and dynamically maps it back to the JSON metadata in the python folder.
    Naturally skips missing translations.
    """
    py_dir = os.path.join(base_dir, "python")
    lang_dir = os.path.join(base_dir, language)
    
    if not os.path.exists(lang_dir):
        print(f"⚠️ Directory {lang_dir} not found. Skipping {language}.")
        return None
        
    # Only loads samples that successfully translated and exist in this folder
    code_files = glob.glob(os.path.join(lang_dir, "*.*"))
    if not code_files:
        print(f"⚠️ No code files found in {lang_dir}. Skipping {language}.")
        return None
        
    all_samples = []
    
    for cf in code_files:
        base_name = os.path.splitext(os.path.basename(cf))[0]
        json_file = os.path.join(py_dir, f"{base_name}.json")
        
        if not os.path.exists(json_file):
            continue # Skip if no matching metadata exists
            
        with open(json_file, "r", encoding="utf-8") as f:
            meta = json.load(f)
            
        with open(cf, "r", encoding="utf-8") as f:
            content = f.read()
            
        # Route terminating to 1 (POSITIVE), non_terminating to 0 (NEGATIVE)
        label_id = 1 if meta.get("label") == "terminating" else 0
        
        all_samples.append({
            "text": content,
            "label": label_id,
            "category": meta.get("category", "unknown"),
            "domain": meta.get("domain", "unknown"),
            "length": meta.get("length", "unknown")
        })
        
    if not all_samples:
        print(f"⚠️ No valid code-metadata pairs found for {language}. Skipping.")
        return None

    # Shuffle and split dataset
    random.seed(seed)
    random.shuffle(all_samples)
    
    split_idx = int(len(all_samples) * (1 - test_size))
    train_samples = all_samples[:split_idx]
    test_samples = all_samples[split_idx:]
    
    train_data = {k: [d[k] for d in train_samples] for k in train_samples[0].keys()}
    test_data = {k: [d[k] for d in test_samples] for k in test_samples[0].keys()}
    
    print(f"[{language.upper()}] Mapped {len(all_samples)} successful translations ({len(train_samples)} Train / {len(test_samples)} Test)")
    
    return DatasetDict({
        "train": Dataset.from_dict(train_data),
        "test": Dataset.from_dict(test_data)
    })

# ==========================================
# 3. METRICS DEFINITION
# ==========================================
accuracy_metric = evaluate.load("accuracy")
precision_metric = evaluate.load("precision")
recall_metric = evaluate.load("recall")
f1_metric = evaluate.load("f1")

def _p_y1_from_logits(z: np.ndarray) -> np.ndarray:
    if z.ndim == 1:
        return 1.0 / (1.0 + np.exp(-z))
    if z.ndim == 2 and z.shape[1] == 1:
        return 1.0 / (1.0 + np.exp(-z[:, 0]))
    if z.ndim == 2 and z.shape[1] == 2:
        e = np.exp(z - z.max(axis=1, keepdims=True))
        p = e / e.sum(axis=1, keepdims=True)
        return p[:, 1]
    raise ValueError(f"Unsupported logits shape: {z.shape}")

def compute_metrics(eval_pred):
    logits, labels = eval_pred
    preds = np.argmax(logits, axis=-1)

    acc = accuracy_metric.compute(predictions=preds, references=labels)
    prec = precision_metric.compute(predictions=preds, references=labels, average="weighted")
    rec = recall_metric.compute(predictions=preds, references=labels, average="weighted")
    f1 = f1_metric.compute(predictions=preds, references=labels, average="weighted")

    y = np.asarray(labels).ravel().astype(int)
    z = np.asarray(logits)

    try: auroc_logit1 = roc_auc_score(y, z[:, 1])
    except Exception: auroc_logit1 = float("nan")

    try:
        scores_pos = _p_y1_from_logits(z)
        auroc_prob = roc_auc_score(y, scores_pos)
    except Exception:
        auroc_prob = float("nan")

    try:
        map_score = average_precision_score(y, preds, average="macro")
    except Exception:
        map_score = float("nan")

    return {
        "accuracy": acc["accuracy"],
        "precision": prec["precision"],
        "recall": rec["recall"],
        "f1": f1["f1"],
        "mAP": map_score,
        "auroc_prob": auroc_prob,
    }

# ==========================================
# 4. TRAINING & EVALUATION PIPELINE
# ==========================================
def train_and_evaluate(language):
    print(f"\n{'='*50}\n🚀 STARTING PIPELINE FOR: {language.upper()}\n{'='*50}")
    
    # 1. Load Data
    raw_dataset = load_cross_language_dataset(language)
    if raw_dataset is None:
        return

    # 2. Tokenize
    tokenizer = AutoTokenizer.from_pretrained(BASE_MODEL)
    if 'gpt2' in BASE_MODEL.lower() and tokenizer.pad_token is None:
        tokenizer.pad_token = tokenizer.eos_token

    def preprocess_function(examples):
        return tokenizer(examples["text"], truncation=True, max_length=512)

    tokenized_dataset = raw_dataset.map(preprocess_function, batched=True)
    data_collator = DataCollatorWithPadding(tokenizer=tokenizer)

    # 3. Initialize Model
    model = AutoModelForSequenceClassification.from_pretrained(
        BASE_MODEL, 
        num_labels=2, 
        id2label={0: "NEGATIVE", 1: "POSITIVE"}, 
        label2id={"NEGATIVE": 0, "POSITIVE": 1},
        use_safetensors=True
    )
    if 'gpt2' in BASE_MODEL.lower():
        model.config.pad_token_id = tokenizer.pad_token_id

    # 4. Configure Trainer (Unique output dir per language)
    training_args = TrainingArguments(
        output_dir=f'outputs/{language}/{BASE_MODEL}',
        logging_dir=f"logs/{language}/{BASE_MODEL}/runs",
        report_to=[], # Disabled tensorboard to avoid log clutter in terminal
        learning_rate=2e-5,
        per_device_train_batch_size=2,  
        per_device_eval_batch_size=4,   
        gradient_accumulation_steps=4,  
        fp16=True,                      
        num_train_epochs=1,     
        weight_decay=0.01,
        eval_strategy="no", 
        save_strategy="no", 
    )

    trainer = Trainer(
        model=model,
        args=training_args,
        train_dataset=tokenized_dataset["train"],
        eval_dataset=tokenized_dataset["test"],
        processing_class=tokenizer, 
        data_collator=data_collator,
        compute_metrics=compute_metrics,
    )

    # 5. Train
    print(f"⚙️ Training model on {language.upper()} code...")
    trainer.train()

    # 6. Granular Evaluation & File Output
    output_filename = f"results_{language}.txt"
    print(f"📊 Evaluating and writing results to {output_filename}...")
    
    test_ds = tokenized_dataset["test"]
    
    with open(output_filename, "w", encoding="utf-8") as f:
        f.write(f"=============================================\n")
        f.write(f"EVALUATION RESULTS FOR LANGUAGE: {language.upper()}\n")
        f.write(f"=============================================\n\n")

        # Overall Metrics
        overall_metrics = trainer.evaluate(test_ds, metric_key_prefix="overall")
        f.write("--- OVERALL TEST METRICS ---\n")
        f.write(json.dumps(overall_metrics, indent=4) + "\n\n")

        # Category Metrics
        f.write("--- METRICS PER CATEGORY ---\n")
        unique_categories = list(set(test_ds["category"]))
        for cat in unique_categories:
            cat_ds = test_ds.filter(lambda x: x["category"] == cat)
            if len(cat_ds) > 0:
                metrics = trainer.evaluate(cat_ds, metric_key_prefix=f"cat_{cat.replace(' ', '_')}")
                f.write(f"[{cat.upper()}]:\n{json.dumps(metrics, indent=4)}\n\n")

        # Domain Metrics
        f.write("--- METRICS PER DOMAIN ---\n")
        unique_domains = list(set(test_ds["domain"]))
        for dom in unique_domains:
            dom_ds = test_ds.filter(lambda x: x["domain"] == dom)
            if len(dom_ds) > 0:
                metrics = trainer.evaluate(dom_ds, metric_key_prefix=f"dom_{dom.replace(' ', '_')}")
                f.write(f"[{dom.upper()}]:\n{json.dumps(metrics, indent=4)}\n\n")
                
        # Length Metrics
        f.write("--- METRICS PER LENGTH ---\n")
        unique_lengths = list(set(test_ds["length"]))
        for length in unique_lengths:
            len_ds = test_ds.filter(lambda x: x["length"] == length)
            if len(len_ds) > 0:
                metrics = trainer.evaluate(len_ds, metric_key_prefix=f"len_{length.replace(' ', '_')}")
                f.write(f"[{length.upper()}]:\n{json.dumps(metrics, indent=4)}\n\n")

    print(f"✅ Finished {language.upper()}. Results saved.")
    
    # 7. Explicit Memory Cleanup & GPU Rest
    print("🧹 Cleaning up GPU memory...")
    del trainer
    del model
    del tokenized_dataset
    gc.collect()
    if torch.cuda.is_available():
        torch.cuda.empty_cache()
        
    print(f"⏳ Resting GPU for {GPU_REST_SECONDS} seconds...")
    time.sleep(GPU_REST_SECONDS)

# ==========================================
# 5. MAIN EXECUTION
# ==========================================
if __name__ == "__main__":
    for lang in LANGUAGES:
        train_and_evaluate(lang)
    
    print("\n🎉 ALL LANGUAGES PROCESSED SUCCESSFULLY!")