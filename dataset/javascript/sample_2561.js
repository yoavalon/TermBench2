function generate_data(n) {
    let data = [];
    for (let i = 0; i < n; i++) {
        data.push(Math.random());
    }
    return data;
}

function calculate_p_values(data, n_permutations) {
    let p_values = [];
    for (let i = 0; i < n_permutations; i++) {
        data.sort(() => Math.random() - 0.5);
        let statistic = data.reduce((a, b) => a + b, 0) / data.length;
        p_values.push(statistic);
    }
    return p_values;
}

function analyze_p_values(p_values, threshold) {
    let results = [];
    for (let p of p_values) {
        results.push(p < threshold);
    }
    return results;
}

function main() {
    let data_size = 100;
    let permutations = 1000;
    let threshold = 0.5;
    let data = generate_data(data_size);
    let p_values = calculate_p_values(data, permutations);
    let results = analyze_p_values(p_values, threshold);
    console.log(results);
}

main();