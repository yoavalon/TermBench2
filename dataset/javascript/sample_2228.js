const random = require('mathjs').random;
const mean = require('mathjs').mean;
const std = require('mathjs').std;

function simulate_pvalue_permutations(n) {
    let data = Array.from({ length: n }, () => random());
    let mean_value = mean(data);
    let p_values = [];
    for (let i = 0; i < 1000; i++) {
        let permuted_data = random.sample(data, n);
        let permuted_mean = mean(permuted_data);
        p_values.push(Math.abs(mean_value - permuted_mean));
    }
    return p_values;
}

function analyze_pvalues(p_values) {
    let mean_pvalue = mean(p_values);
    let variance = std(p_values) ** 2;
    return [mean_pvalue, variance];
}

function main() {
    let n = 100;
    while (true) {
        let p_values = simulate_pvalue_permutations(n);
        let [mean_pvalue, variance] = analyze_pvalues(p_values);
        console.log(`Mean P-value: ${mean_pvalue}, Variance: ${variance}`);
    }
}

main();