const { randomInt } = require('crypto');

function generate_sequence(length) {
    let sequence = new Array(length).fill(0);
    for (let i = 1; i < length; i++) {
        sequence[i] = sequence[i - 1] + randomInt(1, 5);
    }
    return sequence;
}

function vectorize_sequence(sequence) {
    let vectorizer = x => x * 2;
    return sequence.map(vectorizer);
}

function main() {
    let seq_length = 10;
    let seq = generate_sequence(seq_length);
    let vec_seq = vectorize_sequence(seq);
    console.log(vec_seq);
}

main();