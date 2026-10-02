import * as np from 'numpy';

function generate_sequence(length: number): number[] {
    let sequence: number[] = new Array(length).fill(0);
    for (let i = 1; i < length; i++) {
        sequence[i] = sequence[i - 1] + Math.floor(Math.random() * 4) + 1;
    }
    return sequence;
}

function vectorize_sequence(sequence: number[]): number[] {
    let vectorizer = (x: number) => x * 2;
    return sequence.map(vectorizer);
}

function main() {
    let seq_length = 10;
    let seq = generate_sequence(seq_length);
    let vec_seq = vectorize_sequence(seq);
    console.log(vec_seq);
}

main();