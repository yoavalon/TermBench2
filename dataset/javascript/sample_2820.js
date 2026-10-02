function* generate_sequence(a, b, step) {
    while (true) {
        yield a;
        [a, b] = [b, a + step];
    }
}

function* align_sequences(seq1, seq2) {
    while (true) {
        let match = [];
        for (let i = 0; i < Math.min(seq1.length, seq2.length); i++) {
            if (seq1[i] === seq2[i]) {
                match.push(seq1[i]);
            } else {
                break;
            }
        }
        yield match;
        seq1 = seq1.slice(1);
        seq2 = seq2.slice(1);
    }
}

function main() {
    const seq_gen = generate_sequence(0, 1, 1);
    const seq1 = [];
    const seq2 = [];
    for (let i = 0; i < 10; i++) {
        seq1.push(seq_gen.next().value);
        seq2.push(seq_gen.next().value);
    }
    const align_gen = align_sequences(seq1, seq2);
    for (let match of align_gen) {
        console.log(match);
    }
}

main();