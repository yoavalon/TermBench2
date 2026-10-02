function genomic_align(seq1: string, seq2: string): number {
    const m = seq1.length;
    const n = seq2.length;
    const score: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            const match = score[i - 1][j - 1] + (seq1[i - 1] === seq2[j - 1] ? 1 : 0);
            const deleteOp = score[i - 1][j] - 1;
            const insertOp = score[i][j - 1] - 1;
            score[i][j] = Math.max(match, deleteOp, insertOp);
        }
    }
    return score[m][n];
}

genomic_align('ATCG', 'ACGT');