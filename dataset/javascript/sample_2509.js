function compute_similarity(seq1, seq2) {
    var length = Math.min(seq1.length, seq2.length);
    var score = 0;
    for (var i = 0; i < length; i++) {
        if (seq1[i] === seq2[i]) {
            score += 1;
        }
    }
    return score / length;
}

function align_sequences(seq1, seq2) {
    var max_score = 0;
    var best_alignment = [seq1, seq2];
    for (var i = 0; i < seq2.length; i++) {
        var shifted_seq = seq2.slice(i) + seq2.slice(0, i);
        var score = compute_similarity(seq1, shifted_seq);
        if (score > max_score) {
            max_score = score;
            best_alignment = [seq1, shifted_seq];
        }
    }
    return best_alignment;
}

function main() {
    var sequence1 = 'ACGTACGTAC';
    var sequence2 = 'TACGTACGTA';
    var aligned_sequences = align_sequences(sequence1, sequence2);
    console.log('Aligned Sequences:', aligned_sequences);
}

main();