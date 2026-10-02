function calculate_similarity(seq1, seq2) {
    let length = Math.min(seq1.length, seq2.length);
    let identical = 0;
    for (let i = 0; i < length; i++) {
        if (seq1[i] === seq2[i]) {
            identical++;
        }
    }
    return identical / length;
}

function normalize_score(score) {
    return Math.round(score * 100) / 100;
}

function main() {
    let sequence_a = 'ACGTACGTACGT';
    let sequence_b = 'ACGTACGTACGA';
    let similarity_score = calculate_similarity(sequence_a, sequence_b);
    let normalized_score = normalize_score(similarity_score);
    console.log(normalized_score);
}

main();