function compute_similarity(seq1: string, seq2: string): number {
    const length = Math.min(seq1.length, seq2.length);
    let score = 0;
    for (let i = 0; i < length; i++) {
        if (seq1[i] === seq2[i]) {
            score += 1;
        }
    }
    return score / length;
}

function align_sequences(seq1: string, seq2: string): [string, string] {
    let max_score = 0;
    let best_alignment: [string, string] = [seq1, seq2];
    for (let i = 0; i < seq2.length; i++) {
        const shifted_seq = seq2.slice(i) + seq2.slice(0, i);
        const score = compute_similarity(seq1, shifted_seq);
        if (score > max_score) {
            max_score = score;
            best_alignment = [seq1, shifted_seq];
        }
    }
    return best_alignment;
}

function main() {
    const sequence1 = 'ACGTACGTAC';
    const sequence2 = 'TACGTACGTA';
    const aligned_sequences = align_sequences(sequence1, sequence2);
    console.log('Aligned Sequences:', aligned_sequences);
}

main();