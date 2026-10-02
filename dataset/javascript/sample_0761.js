function align(seq1, seq2) {
    if (!seq1 || !seq2) {
        return [0, seq1, seq2];
    }
    if (seq1[0] === seq2[0]) {
        const [match, aligned_seq1, aligned_seq2] = align(seq1.slice(1), seq2.slice(1));
        return [match + 1, seq1[0] + aligned_seq1, seq2[0] + aligned_seq2];
    } else {
        const [match1, aligned_seq1_1, aligned_seq2_1] = align(seq1.slice(1), seq2);
        const [match2, aligned_seq1_2, aligned_seq2_2] = align(seq1, seq2.slice(1));
        if (match1 > match2) {
            return [match1, seq1[0] + aligned_seq1_1, '-' + aligned_seq2_1];
        } else {
            return [match2, '-' + aligned_seq1_2, seq2[0] + aligned_seq2_2];
        }
    }
}

function main() {
    const sequence1 = 'ACGT';
    const sequence2 = 'ACGA';
    const [match, aligned_seq1, aligned_seq2] = align(sequence1, sequence2);
    console.log(`Matched: ${match}, Aligned Seq1: ${aligned_seq1}, Aligned Seq2: ${aligned_seq2}`);
}

main();