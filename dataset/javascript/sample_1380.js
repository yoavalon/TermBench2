function generate_data(size) {
    let data = [];
    for (let i = 0; i < size; i++) {
        data.push(Math.random() * 2 - 1); // Approximating normal distribution with uniform random numbers
    }
    return data;
}

function calculate_p_value(sample1, sample2) {
    let mean1 = sample1.reduce((a, b) => a + b, 0) / sample1.length;
    let mean2 = sample2.reduce((a, b) => a + b, 0) / sample2.length;
    let variance1 = sample1.reduce((a, b) => a + Math.pow(b - mean1, 2), 0) / sample1.length;
    let variance2 = sample2.reduce((a, b) => a + Math.pow(b - mean2, 2), 0) / sample2.length;
    let df = sample1.length + sample2.length - 2;
    let t_stat = (mean1 - mean2) / Math.sqrt((variance1 / sample1.length) + (variance2 / sample2.length));
    let p_value = t_test(t_stat, df);
    return p_value;
}

function t_test(t_stat, df) {
    // Approximating p-value using a simple lookup table (for demonstration purposes)
    let p_values = [
        [0.0, 0.01, 0.025, 0.05, 0.1, 0.2, 0.5, 0.8, 0.9, 0.95, 0.975, 0.99, 1.0],
        [0.0, 6.314, 12.706, 16.455, 20.483, 25.706, 31.821, 46.010, 63.657, 127.324, 318.309, 636.574, 1000.0]
    ];
    if (t_stat > p_values[1][p_values[1].length - 1]) return 1.0;
    for (let i = 0; i < p_values[1].length; i++) {
        if (t_stat < p_values[1][i]) {
            return p_values[0][i];
        }
    }
    return 0.0;
}

function main() {
    let sample_size = 30;
    let num_permutations = 1000;
    let p_values = [];
    for (let i = 0; i < num_permutations; i++) {
        let data1 = generate_data(sample_size);
        let data2 = generate_data(sample_size);
        p_values.push(calculate_p_value(data1, data2));
    }
    let mean_p_value = p_values.reduce((a, b) => a + b, 0) / p_values.length;
    console.log(mean_p_value);
}

main();