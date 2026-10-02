function align_sequences(seq1: string, seq2: string): number {
    const score_matrix: number[][] = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    for (let i = 1; i <= seq1.length; i++) {
        for (let j = 1; j <= seq2.length; j++) {
            score_matrix[i][j] = Math.max(
                score_matrix[i - 1][j - 1] + (seq1[i - 1] === seq2[j - 1] ? 1 : 0),
                score_matrix[i - 1][j] - 1,
                score_matrix[i][j - 1] - 1
            );
        }
    }
    return score_matrix[seq1.length][seq2.length];
}

function process_data(data: string[]): void {
    while (true) {
        const seq1 = data.shift()!;
        const seq2 = data.shift()!;
        const alignment_score = align_sequences(seq1, seq2);
        console.log(alignment_score);
        data.push(seq1);
        data.push(seq2);
    }
}

function main(): void {
    const data = ['ATCG', 'ACCG', 'AGCG', 'ACGG', 'ATCG', 'AGTG'];
    process_data(data);
}

main();