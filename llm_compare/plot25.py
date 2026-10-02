import pandas as pd
import numpy as np
from sklearn.metrics import average_precision_score
import matplotlib.pyplot as plt
import seaborn as sns
import os

files = {
    "Gemini 3 Flash": "termination_results_gemini_3_flash.csv",
    "Gemini 3 Pro": "termination_results_gemini_3_pro.csv",
    "GPT-5 Luna": "termination_results_gpt5_luna.csv",
    "GPT-6 Luna": "termination_results_gpt6_luna.csv",
    "Claude Sonnet 5.5": "termination_results_claude-sonnet-5-5.csv",
    "Claude Opus 5.5": "termination_results_claude_opus_5_5.csv"
}

def calc_map(group):
    y = group['ground_truth'].values
    preds = group['prediction'].values
    if len(np.unique(y)) < 2:
        return np.nan
    try:
        return average_precision_score(y, preds, average="macro")
    except:
        return np.nan

all_results = []
for model_name, file_name in files.items():
    if not os.path.exists(file_name):
        print(f"Missing: {file_name}")
        continue
        
    df = pd.read_csv(file_name)
    # Strictly penalize invalid/missing predictions as the incorrect class
    df['prediction'] = df.apply(
        lambda row: 1 - int(row['ground_truth']) if pd.isna(row['prediction']) else int(row['prediction']),
        axis=1
    )
    df['ground_truth'] = df['ground_truth'].astype(int)
    
    for dimension, col in [('Length', 'length'), ('Category', 'category'), ('Language', 'language')]:
        res = df.groupby(col).apply(calc_map).reset_index()
        res.columns = ['Subcategory', 'mAP']
        res['Dimension'] = dimension
        res['Model'] = model_name
        all_results.append(res)

plot_df = pd.concat(all_results, ignore_index=True)

# ==========================================
# SCIENTIFIC HEATMAP CONFIGURATION
# ==========================================
plt.rcParams.update({
    "font.family": "serif",
    "axes.titlesize": 14,
    "axes.labelsize": 12,
    "xtick.labelsize": 11,
    "ytick.labelsize": 11
})

# Create a figure with a custom grid layout
fig = plt.figure(figsize=(16, 10))
gs = fig.add_gridspec(2, 2, width_ratios=[1, 1.5], height_ratios=[1, 1.2], hspace=0.3, wspace=0.1)

ax_len = fig.add_subplot(gs[0, 0])
ax_cat = fig.add_subplot(gs[0, 1])
ax_lang = fig.add_subplot(gs[1, :])

axes_dict = {'Length': ax_len, 'Category': ax_cat, 'Language': ax_lang}
titles = {
    'Length': '(a) mAP by Code Length',
    'Category': '(b) mAP by Algorithmic Category',
    'Language': '(c) mAP by Programming Language'
}

# Order the categorical variables logically
order_dict = {
    'Length': ['short', 'medium', 'long'],
    'Category': sorted(plot_df[plot_df['Dimension']=='Category']['Subcategory'].unique()),
    'Language': sorted(plot_df[plot_df['Dimension']=='Language']['Subcategory'].unique())
}
model_order = list(files.keys())

for dim in ['Length', 'Category', 'Language']:
    ax = axes_dict[dim]
    sub_df = plot_df[plot_df['Dimension'] == dim]
    
    # Pivot for heatmap
    pivot_df = sub_df.pivot(index='Model', columns='Subcategory', values='mAP')
    pivot_df = pivot_df.reindex(index=model_order, columns=order_dict[dim])
    
    # Generate Heatmap
    sns.heatmap(
        pivot_df, 
        annot=True, 
        fmt=".3f", 
        cmap="YlGnBu",
        #cmap="YlGnBu", 
        ax=ax, 
        cbar=(dim == 'Language'), # Only show a unified colorbar on the bottom plot
        cbar_kws={'label': 'Mean Average Precision (mAP)', 'orientation': 'horizontal', 'pad': 0.2, 'shrink': 0.5} if dim == 'Language' else None,
        vmin=0.4, 
        vmax=1.0,
        linewidths=1,
        linecolor='white'
    )
    
    ax.set_title(titles[dim], fontweight='bold', loc='left', pad=15)
    ax.set_xlabel('')
    ax.set_ylabel('')
    
    # Adjust tick labels for readability
    if dim == 'Language':
        ax.set_xticklabels(ax.get_xticklabels(), rotation=0)
    else:
        ax.set_xticklabels(ax.get_xticklabels(), rotation=15, ha='right')

    # Remove Y labels for category plot to prevent redundancy
    if dim == 'Category':
        ax.set_yticks([])

#plt.savefig('heatmap_evaluation.pdf', format='pdf', bbox_inches='tight')
plt.savefig('heatmap_evaluation.png', dpi=300, bbox_inches='tight')
print("Successfully generated heatmap_evaluation.pdf")