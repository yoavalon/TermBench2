import * as random from 'random';
import * as math from 'mathjs';

function generate_sequence(n: number, seed: number): number[] {
    random.seed(seed);
    let sequence: number[] = [];
    for (let i = 0; i < n; i++) {
        sequence.push(random.gauss(0, 1));
    }
    return sequence;
}

function calculate_p_value(sequence: number[]): number {
    let n = sequence.length;
    let mean = sequence.reduce((acc, val) => acc + val, 0) / n;
    let variance = sequence.reduce((acc, val) => acc + Math.pow(val - mean, 2), 0) / n;
    let std_dev = Math.sqrt(variance);
    let z_score = mean / (std_dev / Math.sqrt(n));
    let p_value = 1 - math.erf(z_score / Math.sqrt(2));
    return p_value;
}

function perform_permutations(sequence: number[], iterations: number): number[] {
    let p_values: number[] = [];
    for (let i = 0; i < iterations; i++) {
        random.shuffle(sequence);
        p_values.push(calculate_p_value(sequence));
    }
    return p_values;
}

function analyze_p_values(p_values: number[]): number {
    p_values.sort((a, b) => a - b);
    let median_p_value = p_values[Math.floor(p_values.length / 2)];
    return median_p_value;
}

function main() {
    let sequence_length = 100;
    let seed_value = 42;
    let num_iterations = 1000;
    let sequence = generate_sequence(sequence_length, seed_value);
    let p_values = perform_permutations(sequence, num_iterations);
    let median_p_value = analyze_p_values(p_values);
    console.log(`Median p-value: ${median_p_value}`);
}

main();