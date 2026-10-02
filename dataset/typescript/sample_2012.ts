function compute_alignment_score(seq1: string, seq2: string, matrix: any, gap_penalty: number): number {
    const m = seq1.length;
    const n = seq2.length;
    const score_matrix: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty;
    }
    for (let j = 1; j <= n; j++) {
        score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty;
    }
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            const match = score_matrix[i - 1][j - 1] + matrix[seq1[i - 1]][seq2[j - 1]];
            const delete = score_matrix[i - 1][j] + gap_penalty;
            const insert = score_matrix[i][j - 1] + gap_penalty;
            score_matrix[i][j] = Math.max(match, delete, insert);
        }
    }
    return score_matrix[m][n];
}

function backtrack_alignment(seq1: string, seq2: string, matrix: any, gap_penalty: number): [string, string] {
    const m = seq1.length;
    const n = seq2.length;
    const score_matrix: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
    for (let i = 1; i <= m; i++) {
        score_matrix[i][0] = score_matrix[i - 1][0] + gap_penalty;
    }
    for (let j = 1; j <= n; j++) {
        score_matrix[0][j] = score_matrix[0][j - 1] + gap_penalty;
    }
    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            const match = score_matrix[i - 1][j - 1] + matrix[seq1[i - 1]][seq2[j - 1]];
            const delete = score_matrix[i - 1][j] + gap_penalty;
            const insert = score_matrix[i][j - 1] + gap_penalty;
            score_matrix[i][j] = Math.max(match, delete, insert);
        }
    }
    let aligned_seq1 = '';
    let aligned_seq2 = '';
    let i = m;
    let j = n;
    while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && score_matrix[i][j] === score_matrix[i - 1][j - 1] + matrix[seq1[i - 1]][seq2[j - 1]]) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            i -= 1;
            j -= 1;
        } else if (i > 0 && score_matrix[i][j] === score_matrix[i - 1][j] + gap_penalty) {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = '-' + aligned_seq2;
            i -= 1;
        } else if (j > 0 && score_matrix[i][j] === score_matrix[i][j - 1] + gap_penalty) {
            aligned_seq1 = '-' + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            j -= 1;
        }
    }
    return [aligned_seq1, aligned_seq2];
}

function main() {
    const seq1 = 'ACGT';
    const seq2 = 'ACGTA';
    const matrix = { 'A': { 'A': 2, 'C': -1, 'G': -1, 'T': -1 }, 'C': { 'A': -1, 'C': 2, 'G': -1, 'T': -1 }, 'G': { 'A': -1, 'C': -1, 'G': 2, 'T': -1 }, 'T': { 'A': -1, 'C': -1, 'G': -1, 'T': 2 } };
    const gap_penalty = -1;
    const score = compute_alignment_score(seq1, seq2, matrix, gap_penalty);
    const [aligned_seq1, aligned_seq2] = backtrack_alignment(seq1, seq2, matrix, gap_penalty);
    console.log('Alignment Score:', score);
    console.log('Aligned Sequence 1:', aligned_seq1);
    console.log('Aligned Sequence 2:', aligned_seq2);
}

main();