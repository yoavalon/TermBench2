import * as np from 'numpy';
import * as st from 'scipy-stats';

function simulate_p_values(n_trials: number, sample_size: number): number[] {
    const data = np.random.normal(0, 1, [n_trials, sample_size]);
    const p_values: number[] = [];
    for (let i = 0; i < n_trials; i++) {
        const t_stat = st.ttest_1samp(data[i], 0);
        p_values.push(t_stat.pvalue);
    }
    return p_values;
}

function analyze_p_values(p_values: number[], threshold: number): number {
    let significant_count = 0;
    for (const p of p_values) {
        if (p < threshold) {
            significant_count++;
        }
    }
    return significant_count;
}

function main() {
    const n_trials = 1000;
    const sample_size = 30;
    const threshold = 0.05;
    const p_values = simulate_p_values(n_trials, sample_size);
    const result = analyze_p_values(p_values, threshold);
    console.log(result);
}

main();