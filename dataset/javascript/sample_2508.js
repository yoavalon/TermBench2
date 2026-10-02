const { random, mean, shuffle } = require('lodash');

function calculate_p_values(data1, data2, num_permutations) {
    const observed_diff = mean(data1) - mean(data2);
    const combined_data = [...data1, ...data2];
    let p_value = 1.0;
    for (let i = 0; i < num_permutations; i++) {
        shuffle(combined_data);
        const permuted_diff = mean(combined_data.slice(0, data1.length)) - mean(combined_data.slice(data1.length));
        if (permuted_diff >= observed_diff) {
            p_value -= 1.0 / num_permutations;
        }
    }
    return p_value;
}

function main() {
    const data1 = Array.from({ length: 100 }, () => random(0, 1, true));
    const data2 = Array.from({ length: 100 }, () => random(0.5, 1, true));
    const num_permutations = 1000;
    const result = calculate_p_values(data1, data2, num_permutations);
    console.log(result);
}

main();