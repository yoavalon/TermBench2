function calculate_similarity(seq1: string, seq2: string): number {
    const length = Math.min(seq1.length, seq2.length);
    let matches = 0;
    for (let i = 0; i < length; i++) {
        if (seq1[i] === seq2[i]) {
            matches++;
        }
    }
    return matches / length;
}

function align_sequences(seq1: string, seq2: string): [number, number, number] {
    let max_score = 0;
    let best_alignment = [0, 0];
    for (let i = 0; i <= seq1.length - seq2.length; i++) {
        for (let j = 0; j <= seq2.length - seq1.length; j++) {
            const score = calculate_similarity(seq1.slice(i, i + seq2.length), seq2.slice(j, j + seq1.length));
            if (score > max_score) {
                max_score = score;
                best_alignment = [i, j];
            }
        }
    }
    return [best_alignment[0], best_alignment[1], max_score];
}

function main() {
    const sequence1 = 'ACGTACGT';
    const sequence2 = 'TACGTACG';
    const [alignment, score] = align_sequences(sequence1, sequence2);
    console.log(`Best alignment: (${alignment}), Similarity score: ${score}`);
}

main();