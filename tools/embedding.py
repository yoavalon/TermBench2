import os
import glob
import json
import numpy as np
import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.decomposition import TruncatedSVD
from sklearn.metrics import pairwise_distances
import matplotlib.pyplot as plt
import seaborn as sns

DATASET_ROOT = os.path.join("dataset", "python")

def load_text_dataset():
    records = []
    json_files = glob.glob(os.path.join(DATASET_ROOT, "*.json"))
    
    if not json_files:
        print(f"No JSON metadata files found in '{DATASET_ROOT}'.")
        return pd.DataFrame()
        
    for jf in json_files:
        py_path = jf.replace(".json", ".py")
        if not os.path.exists(py_path):
            continue
            
        with open(jf, "r", encoding="utf-8") as f:
            meta = json.load(f)
            
        with open(py_path, "r", encoding="utf-8") as f:
            raw_text = f.read()
            
        meta["raw_code_text"] = raw_text
        records.append(meta)
        
    return pd.DataFrame(records)

def main():
    df = load_text_dataset()
    if df.empty:
        return

    # 1. Text Vectorization
    print("Vectorizing raw text using TF-IDF...")
    tfidf = TfidfVectorizer(
        token_pattern=r"(?u)\b\w+\b|[=+\-*/<>:!]+", 
        ngram_range=(1, 2), 
        max_features=1000
    )
    text_matrix = tfidf.fit_transform(df["raw_code_text"])

    # 2. Diversity Score
    p_dist = pairwise_distances(text_matrix, metric="cosine")
    avg_dist = np.mean(p_dist[np.triu_indices_from(p_dist, k=1)])
    print(f"\n📈 Quantitative Text Diversity Score (Cosine Distance): {avg_dist:.4f}")

    # 3. Dimensionality Reduction
    print("Reducing dimensions to 2D for visualization...")
    svd = TruncatedSVD(n_components=2, random_state=42)
    coords = svd.fit_transform(text_matrix)

    df["Dim1"] = coords[:, 0]
    df["Dim2"] = coords[:, 1]
    var_explained = svd.explained_variance_ratio_ * 100

    # 4. Scientific Plotting Setup
    print("Generating scientific PNG map...")
    
    # Configure academic aesthetics (serif fonts, clean grid, standard proportions)
    plt.rcParams.update({
        "font.family": "serif",
        "axes.labelsize": 12,
        "axes.titlesize": 14,
        "legend.fontsize": 10,
        "legend.title_fontsize": 11,
        "figure.figsize": (10, 7),
        "figure.dpi": 300,
        "axes.grid": True,
        "grid.alpha": 0.3,
        "grid.linestyle": "--"
    })
    
    fig, ax = plt.subplots()

    # Scatter plot with pastel colors and increased transparency (alpha)
    sns.scatterplot(
        data=df,
        x="Dim1",
        y="Dim2",
        hue="category",
        style="label",
        palette="pastel",
        s=90,
        alpha=0.6,
        edgecolor="black",
        linewidth=0.5,
        ax=ax
    )

    ax.set_title(f"Textual Diversity Map (TF-IDF + LSA)\nAverage Cosine Distance: {avg_dist:.2f}", pad=15)
    ax.set_xlabel(f"First Principal Component ({var_explained[0]:.1f}% Variance Explained)")
    ax.set_ylabel(f"Second Principal Component ({var_explained[1]:.1f}% Variance Explained)")
    
    # Clean up legend and axes
    handles, labels = ax.get_legend_handles_labels()
    ax.legend(handles, labels, bbox_to_anchor=(1.02, 1), loc='upper left', frameon=False)
    sns.despine(ax=ax, top=True, right=True)
    
    plt.tight_layout()

    output_file = "dataset_diversity_map.png"
    plt.savefig(output_file, bbox_inches="tight", dpi=300)
    print(f"✅ Scientific map saved to: {output_file}")

if __name__ == "__main__":
    main()