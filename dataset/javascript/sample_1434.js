function generate_data(size) {
    const data1 = new Array(size).fill(0).map(() => Math.random() * 2 - 1);
    const data2 = new Array(size).fill(0).map(() => (Math.random() * 2 - 1) + 0.5);
    return [data1, data2];
}

function perform_ttest(data1, data2) {
    const n1 = data1.length;
    const n2 = data2.length;
    const mean1 = data1.reduce((a, b) => a + b, 0) / n1;
    const mean2 = data2.reduce((a, b) => a + b, 0) / n2;
    const var1 = data1.reduce((a, b) => a + Math.pow(b - mean1, 2), 0) / (n1 - 1);
    const var2 = data2.reduce((a, b) => a + Math.pow(b - mean2, 2), 0) / (n2 - 1);
    const pooledVar = ((n1 - 1) * var1 + (n2 - 1) * var2) / (n1 + n2 - 2);
    const t_stat = (mean1 - mean2) / Math.sqrt(pooledVar * (1 / n1 + 1 / n2));
    const df = n1 + n2 - 2;
    const p_value = tDist(df, Math.abs(t_stat)) * 2; // Two-tailed p-value
    return [t_stat, p_value];
}

function tDist(df, t) {
    // Approximation for t-distribution CDF
    const a = 1 / (Math.sqrt(df / 2) * gamma(df / 2));
    const b = Math.pow(1 + t * t / df, -(df + 1) / 2);
    return a * b;
}

function gamma(n) {
    // Simple approximation for gamma function
    if (n < 1) return 0;
    if (n <= 2) return 1;
    return (n - 1) * gamma(n - 1);
}

function permute_data(data1, data2, iterations) {
    const p_values = [];
    for (let i = 0; i < iterations; i++) {
        const combined = data1.concat(data2);
        for (let j = combined.length - 1; j > 0; j--) {
            const k = Math.floor(Math.random() * (j + 1));
            [combined[j], combined[k]] = [combined[k], combined[j]];
        }
        const permuted_data1 = combined.slice(0, data1.length);
        const permuted_data2 = combined.slice(data1.length);
        const [, permuted_p_value] = perform_ttest(permuted_data1, permuted_data2);
        p_values.push(permuted_p_value);
    }
    return p_values;
}

function analyze_p_values(p_values, original_p_value, alpha = 0.05) {
    const less_extreme = p_values.filter(p => p <= original_p_value);
    const p_value_permutation = less_extreme.length / p_values.length;
    return p_value_permutation < alpha;
}

function main() {
    const [data1, data2] = generate_data(30);
    const [t_stat, original_p_value] = perform_ttest(data1, data2);
    const p_values = permute_data(data1, data2, 1000);
    const result = analyze_p_values(p_values, original_p_value);
    console.log(result);
}

main();