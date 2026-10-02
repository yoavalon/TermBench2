class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
        this.score_matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    initialize_matrices() {
        for (let i = 0; i <= this.seq1.length; i++) {
            this.matrix[i][0] = i;
            this.score_matrix[i][0] = i * -2;
        }
        for (let j = 0; j <= this.seq2.length; j++) {
            this.matrix[0][j] = j;
            this.score_matrix[0][j] = j * -2;
        }
    }

    calculate_scores() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const match = this.score_matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : -1);
                const deleteOp = this.score_matrix[i - 1][j] - 2;
                const insert = this.score_matrix[i][j - 1] - 2;
                this.score_matrix[i][j] = Math.max(match, deleteOp, insert);
            }
        }
    }

    trace_back() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let aligned_seq1 = '';
        let aligned_seq2 = '';
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && this.score_matrix[i][j] === this.score_matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : -1)) {
                aligned_seq1 = this.seq1[i - 1] + aligned_seq1;
                aligned_seq2 = this.seq2[j - 1] + aligned_seq2;
                i -= 1;
                j -= 1;
            } else if (i > 0 && this.score_matrix[i][j] === this.score_matrix[i - 1][j] - 2) {
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
    const seq1 = 'GATTACA';
    const seq2 = 'GATTCACA';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.initialize_matrices();
    aligner.calculate_scores();
    const [aligned_seq1, aligned_seq2] = aligner.trace_back();
    console.log('Aligned Sequence 1:', aligned_seq1);
    console.log('Aligned Sequence 2:', aligned_seq2);
}

main();