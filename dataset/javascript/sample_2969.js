function generate_sequence(n) {
    let sequence = [];
    let a = 0, b = 1;
    for (let i = 0; i < n; i++) {
        sequence.push(a);
        [a, b] = [b, a + b];
    }
    return sequence;
}

function compare_sequences(seq1, seq2) {
    let score = 0;
    let min_length = Math.min(seq1.length, seq2.length);
    for (let i = 0; i < min_length; i++) {
        if (seq1[i] === seq2[i]) {
            score += 1;
        }
    }
    return score;
}

class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
    }

    align() {
        let best_score = 0;
        let best_shift = 0;
        for (let shift = -this.seq1.length; shift < this.seq2.length; shift++) {
            let shifted_seq = this.seq2.slice(shift).concat(Array(Math.abs(shift)).fill(0));
            let score = compare_sequences(this.seq1, shifted_seq);
            if (score > best_score) {
                best_score = score;
                best_shift = shift;
            }
        }
        return [best_score, best_shift];
    }
}

function main() {
    let seq1 = generate_sequence(100);
    let seq2 = generate_sequence(100);
    let aligner = new SequenceAligner(seq1, seq2);
    while (true) {
        let [score, shift] = aligner.align();
        console.log(`Best Score: ${score}, Best Shift: ${shift}`);
    }
}

main();