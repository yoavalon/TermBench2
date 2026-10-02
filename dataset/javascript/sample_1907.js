function simulatePValues(n_trials, sample_size) {
    let data = [];
    for (let i = 0; i < n_trials; i++) {
        data.push([]);
        for (let j = 0; j < sample_size; j++) {
            data[i][j] = Math.random() * 2 - 1; // Simulating normal distribution with mean 0 and std 1
        }
    }
    let p_values = [];
    for (let i = 0; i < n_trials; i++) {
        let t_stat = 0;
        let mean = data[i].reduce((a, b) => a + b, 0) / sample_size;
        let variance = data[i].reduce((a, b) => a + Math.pow(b - mean, 2), 0) / sample_size;
        let se = Math.sqrt(variance / sample_size);
        t_stat = (mean - 0) / se;
        let df = sample_size - 1;
        let p_val = 2 * (1 - tCDF(t_stat, df)); // Using tCDF function to calculate p-value
        p_values.push(p_val);
    }
    return p_values;
}

function tCDF(t, df) {
    let prob = jStat.studentt.cdf(t, df);
    return prob;
}

function analyzePValues(p_values, threshold) {
    let significant_count = 0;
    for (let p of p_values) {
        if (p < threshold) {
            significant_count++;
        }
    }
    return significant_count;
}

function main() {
    let n_trials = 1000;
    let sample_size = 30;
    let threshold = 0.05;
    let p_values = simulatePValues(n_trials, sample_size);
    let result = analyzePValues(p_values, threshold);
    console.log(result);
}

main();