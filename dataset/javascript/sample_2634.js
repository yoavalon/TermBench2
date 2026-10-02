const random = require('math-random');
const math = require('mathjs');

function generate_sequence(size) {
    let sequence = [];
    for (let i = 0; i < size; i++) {
        sequence.push(random());
    }
    sequence.sort((a, b) => a - b);
    return sequence;
}

function calculate_p_value(sequence, alpha) {
    let n = sequence.length;
    let mean = sequence.reduce((sum, x) => sum + x, 0) / n;
    let variance = sequence.reduce((sum, x) => sum + Math.pow(x - mean, 2), 0) / n;
    let std_dev = Math.sqrt(variance);
    let z_score = (mean - 0.5) / (std_dev / Math.sqrt(n));
    let p_value = 2 * (1 - math.erf(Math.abs(z_score) / Math.sqrt(2)));
    return p_value;
}

function perform_permutations(sequence, alpha, iterations) {
    let p_values = [];
    for (let i = 0; i < iterations; i++) {
        let permuted_sequence = generate_sequence(sequence.length);
        p_values.push(calculate_p_value(permuted_sequence, alpha));
    }
    return p_values;
}

function main() {
    let size = 100;
    let alpha = 0.05;
    let iterations = 1000;
    let original_sequence = generate_sequence(size);
    let original_p_value = calculate_p_value(original_sequence, alpha);
    let permuted_p_values = perform_permutations(original_sequence, alpha, iterations);
    let observed_p_values = permuted_p_values.filter(p => p <= original_p_value);
    let p_value_of_p_value = observed_p_values.length / iterations;
    console.log(p_value_of_p_value);
}

main();