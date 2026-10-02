import { random, sqrt, erf } from 'mathjs';

function generate_sequence(size: number): number[] {
    const sequence = Array.from({ length: size }, () => random());
    sequence.sort((a, b) => a - b);
    return sequence;
}

function calculate_p_value(sequence: number[], alpha: number): number {
    const n = sequence.length;
    const mean = sequence.reduce((sum, x) => sum + x, 0) / n;
    const variance = sequence.reduce((sum, x) => sum + Math.pow(x - mean, 2), 0) / n;
    const std_dev = sqrt(variance);
    const z_score = (mean - 0.5) / (std_dev / sqrt(n));
    const p_value = 2 * (1 - erf(abs(z_score) / sqrt(2)));
    return p_value;
}

function perform_permutations(sequence: number[], alpha: number, iterations: number): number[] {
    const p_values: number[] = [];
    for (let i = 0; i < iterations; i++) {
        const permuted_sequence = generate_sequence(sequence.length);
        p_values.push(calculate_p_value(permuted_sequence, alpha));
    }
    return p_values;
}

function main() {
    const size = 100;
    const alpha = 0.05;
    const iterations = 1000;
    const original_sequence = generate_sequence(size);
    const original_p_value = calculate_p_value(original_sequence, alpha);
    const permuted_p_values = perform_permutations(original_sequence, alpha, iterations);
    const observed_p_values = permuted_p_values.filter(p => p <= original_p_value);
    const p_value_of_p_value = observed_p_values.length / iterations;
    console.log(p_value_of_p_value);
}

main();