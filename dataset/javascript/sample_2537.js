const { random, shuffle } = require('lodash');

function generate_sequence(n) {
    let seq = [];
    for (let i = 0; i < n; i++) {
        seq.push(Math.random());
    }
    seq.sort((a, b) => a - b);
    return seq;
}

function calculate_p_values(seq1, seq2, k) {
    let p_values = [];
    for (let i = 0; i < k; i++) {
        shuffle(seq1);
        shuffle(seq2);
        let diff = seq1.reduce((acc, a, idx) => acc + (a > seq2[idx] ? 1 : 0), 0) / seq1.length;
        p_values.push(diff);
    }
    return p_values;
}

function main() {
    let seq1 = generate_sequence(50);
    let seq2 = generate_sequence(50);
    let p_values = calculate_p_values(seq1, seq2, 1000);
    console.log(p_values);
}

main();