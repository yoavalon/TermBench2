class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
    }

    score(a, b) {
        return a === b ? 1 : -1;
    }

    align() {
        const m = this.seq1.length;
        const n = this.seq2.length;
        const matrix = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
        for (let i = 1; i <= m; i++) {
            matrix[i][0] = i;
        }
        for (let j = 1; j <= n; j++) {
            matrix[0][j] = j;
        }
        for (let i = 1; i <= m; i++) {
            for (let j = 1; j <= n; j++) {
                const match = matrix[i - 1][j - 1] + this.score(this.seq1[i - 1], this.seq2[j - 1]);
                const deleteOp = matrix[i - 1][j] + 1;
                const insert = matrix[i][j - 1] + 1;
                matrix[i][j] = Math.min(match, deleteOp, insert);
            }
        }
        return this.traceback(matrix, m, n);
    }

    traceback(matrix, i, j) {
        let align1 = '';
        let align2 = '';
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && matrix[i][j] === matrix[i - 1][j - 1] + this.score(this.seq1[i - 1], this.seq2[j - 1])) {
                align1 = this.seq1[i - 1] + align1;
                align2 = this.seq2[j - 1] + align2;
                i -= 1;
                j -= 1;
            } else if (i > 0 && matrix[i][j] === matrix[i - 1][j] + 1) {
                align1 = this.seq1[i - 1] + align1;
                align2 = '-' + align2;
                i -= 1;
            } else {
                align1 = '-' + align1;
                align2 = this.seq2[j - 1] + align2;
                j -= 1;
            }
        }
        return [align1, align2];
    }
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const aligner = new SequenceAligner(seq1, seq2);
    const result = aligner.align();
    console.log('Alignment 1:', result[0]);
    console.log('Alignment 2:', result[1]);
}

main();