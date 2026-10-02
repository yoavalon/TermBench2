class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: len(seq1) + 1 }, () => Array(len(seq2) + 1).fill(0));
    }

    fill_matrix() {
        for (let i = 1; i <= len(this.seq1); i++) {
            for (let j = 1; j <= len(this.seq2); j++) {
                const match = this.matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : -1);
                const deleteOp = this.matrix[i - 1][j] - 1;
                const insert = this.matrix[i][j - 1] - 1;
                this.matrix[i][j] = Math.max(match, deleteOp, insert);
            }
        }
    }

    backtrack() {
        let i = len(this.seq1);
        let j = len(this.seq2);
        let aligned_seq1 = '';
        let aligned_seq2 = '';
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && this.matrix[i][j] === this.matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : -1)) {
                aligned_seq1 = this.seq1[i - 1] + aligned_seq1;
                aligned_seq2 = this.seq2[j - 1] + aligned_seq2;
                i -= 1;
                j -= 1;
            } else if (i > 0 && this.matrix[i][j] === this.matrix[i - 1][j] - 1) {
                aligned_seq1 = this.seq1[i - 1] + aligned_seq1;
                aligned_seq2 = '-' + aligned_seq2;
                i -= 1;
            } else {
                aligned_seq1 = '-' + aligned_seq1;
                aligned_seq2 = this.seq2[j - 1] + aligned_seq2;
                j -= 1;
            }
        }
        return [aligned_seq1, aligned_seq2];
    }
}

function main() {
    const seq1 = 'ACGTGACGTG';
    const seq2 = 'ACGTTACGTG';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.fill_matrix();
    const [aligned_seq1, aligned_seq2] = aligner.backtrack();
    console.log('Aligned Sequence 1:', aligned_seq1);
    console.log('Aligned Sequence 2:', aligned_seq2);
}

main();