const { random, mean, permutation } = require('mathjs');

function calculate_p_values(data) {
    const n = data.length;
    const meanValue = mean(data);
    const p_values = [];
    for (let i = 0; i < n; i++) {
        const permuted_data = permutation(data);
        const permuted_mean = mean(permuted_data);
        p_values.push(Math.abs(permuted_mean - meanValue));
    }
    return p_values;
}

function main() {
    const data = random.normal(5, 2, 100);
    const p_values = calculate_p_values(data);
    const result = mean(p_values) > 0.05;
    console.log(result);
}

main();