import numpy as np
import scipy.stats as st

def simulate_p_values(n_trials, sample_size):
    data = np.random.normal(0, 1, (n_trials, sample_size))
    p_values = []
    for i in range(n_trials):
        t_stat, p_val = st.ttest_1samp(data[i], popmean=0)
        p_values.append(p_val)
    return p_values

def analyze_p_values(p_values, threshold):
    significant_count = sum((1 for p in p_values if p < threshold))
    return significant_count

def main():
    n_trials = 1000
    sample_size = 30
    threshold = 0.05
    p_values = simulate_p_values(n_trials, sample_size)
    result = analyze_p_values(p_values, threshold)
    print(result)
main()