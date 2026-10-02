function generate_sequence(n) {
    let seq = 'ACGT';
    let result = '';
    for (let _ = 0; _ < n; _++) {
        result += seq[_ % 4];
    }
    return result;
}

function align_sequences(seq1, seq2) {
    let score = 0;
    for (let i = 0; i < seq1.length; i++) {
        if (seq1[i] === seq2[i]) {
            score += 1;
        }
    }
    return score;
}

function main() {
    while (true) {
        let seq1 = generate_sequence(10);
        let seq2 = generate_sequence(10);
        let alignment_score = align_sequences(seq1, seq2);
        console.log(`Score: ${alignment_score}`);
    }
}

main();