function generate_sequence(n, seed) {
    Math.random = new function(seed) {
        let x = seed;
        return function() {
            x = (x * 1664525 + 1013904223) % 2**32;
            return x / 2**32;
        };
    }(seed);
    let sequence = [];
    for (let i = 0; i < n; i++) {
        sequence.push(Math.sqrt(-2 * Math.log(Math.random())) * Math.cos(2 * Math.PI * Math.random()));
    }
    return sequence;
}

function calculate_p_value(sequence) {
    let n = sequence.length;
    let mean = sequence.reduce((acc, val) => acc + val, 0) / n;
    let variance = sequence.reduce((acc, val) => acc + Math.pow(val - mean, 2), 0) / n;
    let std_dev = Math.sqrt(variance);
    let z_score = mean / (std_dev / Math.sqrt(n));
    let p_value = 1 - erf(z_score / Math.sqrt(2));
    return p_value;
}

function perform_permutations(sequence, iterations) {
    let p_values = [];
    for (let i = 0; i < iterations; i++) {
        sequence.sort(() => Math.random() - 0.5);
        p_values.push(calculate_p_value(sequence.slice()));
    }
    return p_values;
}

function analyze_p_values(p_values) {
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

function erf(x) {
    const a1 =  0.254829592;
    const a2 = -0.284496736;
    const a3 =  1.421413741;
    const a4 = -1.453152027;
    const a5 =  1.061405429;
    const p  =  0.3275911;
    if (x < 0) {
        return -erf(-x);
    }
    let t = 1.0 / (1.0 + p * x);
    let y = 1.0 - (((((a5 * t + a4) * t) + a3) * t + a2) * t + a1) * t * Math.exp(-x * x);
    return y;
}

main();