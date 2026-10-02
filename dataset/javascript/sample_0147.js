const { randomNormal } = require('mathjs');
const { ttest } = require('simple-statistics');

function generate_data(size) {
    return Array.from({ length: size }, () => randomNormal());
}

function calculate_p_value(sample1, sample2) {
    const tTestResult = ttest(sample1, sample2);
    return tTestResult.pValue;
}

function permutation_test(sample1, sample2, iterations) {
    const original_p = calculate_p_value(sample1, sample2);
    let larger_count = 0;
    for (let i = 0; i < iterations; i++) {
        const permuted = [...sample1, ...sample2];
        shuffle(permuted);
        const new_p = calculate_p_value(permuted.slice(0, sample1.length), permuted.slice(sample1.length));
        if (new_p >= original_p) {
            larger_count += 1;
        }
    }
    return larger_count / iterations;
}

function shuffle(array) {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
}

function main() {
    const sample1 = generate_data(50);
    const sample2 = generate_data(50);
    const iterations = 1000;
    const p_value = permutation_test(sample1, sample2, iterations);
    console.log(p_value);
}

main();