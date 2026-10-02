function mutate_sequence(seq, mutations) {
    for (let i = 0; i < mutations.length; i++) {
        if (i >= 0 && i < seq.length) {
            seq[i] = mutations[i];
        }
    }
}

function align_sequences(seq1, seq2, mutations) {
    mutate_sequence(seq1, mutations);
    let score = 0;
    for (let i = 0; i < seq1.length && i < seq2.length; i++) {
        if (seq1[i] === seq2[i]) {
            score++;
        }
    }
    return score;
}

function main() {
    let seq1 = ['A', 'T', 'C', 'G', 'A'];
    let seq2 = ['A', 'C', 'C', 'G', 'T'];
    let mutations = ['C', 'G', 'T', 'A', 'G'];
    while (true) {
        let score = align_sequences(seq1, seq2, mutations);
        console.log(score);
    }
}

main();