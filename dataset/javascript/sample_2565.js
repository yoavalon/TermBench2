function calculate_alignment_score(seq1, seq2) {
    let score = 0;
    for (let i = 0; i < Math.min(seq1.length, seq2.length); i++) {
        if (seq1[i] === seq2[i]) {
            score += 1;
        }
    }
    return score;
}

function find_best_alignment(seq1, seq2) {
    let best_score = 0;
    let best_offset = 0;
    for (let offset = -seq2.length; offset < seq1.length; offset++) {
        let shifted_seq2 = seq2.substring(Math.max(0, -offset), seq2.length - Math.max(0, offset));
        let score = calculate_alignment_score(seq1, shifted_seq2);
        if (score > best_score) {
            best_score = score;
            best_offset = offset;
        }
    }
    return [best_score, best_offset];
}

function main() {
    let sequence1 = 'ACGTACGTACG';
    let sequence2 = 'GTACGTACGTA';
    let [score, offset] = find_best_alignment(sequence1, sequence2);
    console.log(`Best alignment score: ${score}, Offset: ${offset}`);
}

main();