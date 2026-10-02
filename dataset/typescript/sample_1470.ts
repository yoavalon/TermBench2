class SequenceAligner {
    seq1: string;
    seq2: string;
    matrix: number[][];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    fill_matrix() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const match = this.matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : -1);
                const deleteOp = this.matrix[i - 1][j] - 1;
                const insert = this.matrix[i][j - 1] - 1;
                this.matrix[i][j] = Math.max(match, deleteOp, insert);
            }
        }
    }

    backtrack() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let aligned_seq1 = '';
        let aligned_seq2 = '';
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && (this.matrix[i][j] === this.matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : -1))) {
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