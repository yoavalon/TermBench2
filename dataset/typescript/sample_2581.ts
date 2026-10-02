function calculate_similarity(seq1: string, seq2: string): number {
    let score = 0;
    const length = Math.min(seq1.length, seq2.length);
    for (let i = 0; i < length; i++) {
        if (seq1[i] === seq2[i]) {
            score += 1;
        }
    }
    return score / length;
}

function find_best_alignment(sequences: string[]): [string[], number] {
    let max_score = 0;
    let best_pair: [string, string] | null = null;
    for (let i = 0; i < sequences.length; i++) {
        for (let j = i + 1; j < sequences.length; j++) {
            const score = calculate_similarity(sequences[i], sequences[j]);
            if (score > max_score) {
                max_score = score;
                best_pair = [sequences[i], sequences[j]];
            }
        }
    }
    return [best_pair as [string, string], max_score];
}

function main() {
    const sequences = ['ATCG', 'ATCC', 'AGCG', 'ACCG'];
    const [best_pair, max_score] = find_best_alignment(sequences);
    console.log(`Best alignment: ${best_pair} with score: ${max_score}`);
}

main();