import { random } from 'lodash';

function generate_sequence(n: number): number[] {
    let seq = Array.from({ length: n }, () => random(0, 1));
    seq.sort((a, b) => a - b);
    return seq;
}

function calculate_p_values(seq1: number[], seq2: number[], k: number): number[] {
    let p_values: number[] = [];
    for (let _ = 0; _ < k; _++) {
        seq1 = seq1.sort(() => Math.random() - 0.5);
        seq2 = seq2.sort(() => Math.random() - 0.5);
        let diff = seq1.reduce((acc, a, i) => acc + (a > seq2[i] ? 1 : 0), 0) / seq1.length;
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