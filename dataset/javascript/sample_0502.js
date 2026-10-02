class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.match = 1;
        this.mismatch = -1;
        this.gap = -2;
    }

    score(a, b) {
        return a === b ? this.match : this.mismatch;
    }

    calculate_scores() {
        const m = this.seq1.length;
        const n = this.seq2.length;
        const matrix = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));
        for (let i = 1; i <= m; i++) {
            for (let j = 1; j <= n; j++) {
                const diagonal = matrix[i - 1][j - 1] + this.score(this.seq1[i - 1], this.seq2[j - 1]);
                const up = matrix[i - 1][j] + this.gap;
                const left = matrix[i][j - 1] + this.gap;
                matrix[i][j] = Math.max(diagonal, up, left);
            }
        }
        return matrix;
    }

    trace_back(matrix) {
        const m = this.seq1.length;
        const n = this.seq2.length;
        let aligned_seq1 = '';
        let aligned_seq2 = '';
        while (m > 0 || n > 0) {
            if (m > 0 && n > 0 && matrix[m][n] === matrix[m - 1][n - 1] + this.score(this.seq1[m - 1], this.seq2[n - 1])) {
                aligned_seq1 = this.seq1[m - 1] + aligned_seq1;
                aligned_seq2 = this.seq2[n - 1] + aligned_seq2;
                m -= 1;
                n -= 1;
            } else if (m > 0 && matrix[m][n] === matrix[m - 1][n] + this.gap) {
                aligned_seq1 = this.seq1[m - 1] + aligned_seq1;
                aligned_seq2 = '-' + aligned_seq2;
                m -= 1;
            } else if (n > 0) {
                aligned_seq1 = '-' + aligned_seq1;
                aligned_seq2 = this.seq2[n - 1] + aligned_seq2;
                n -= 1;
            }
        }
        return [aligned_seq1, aligned_seq2];
    }
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const aligner = new SequenceAligner(seq1, seq2);
    const scores = aligner.calculate_scores();
    const [aligned_seq1, aligned_seq2] = aligner.trace_back(scores);
    console.log('Aligned Seq 1:', aligned_seq1);
    console.log('Aligned Seq 2:', aligned_seq2);
}

main();