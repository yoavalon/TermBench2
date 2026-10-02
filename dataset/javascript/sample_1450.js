class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    build_matrix() {
        for (let i = 0; i <= this.seq1.length; i++) {
            for (let j = 0; j <= this.seq2.length; j++) {
                if (i === 0 || j === 0) {
                    this.matrix[i][j] = 0;
                } else if (this.seq1[i - 1] === this.seq2[j - 1]) {
                    this.matrix[i][j] = this.matrix[i - 1][j - 1] + 1;
                } else {
                    this.matrix[i][j] = Math.max(this.matrix[i - 1][j], this.matrix[i][j - 1]);
                }
            }
        }
    }

    trace_back() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let align1 = '';
        let align2 = '';
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                align1 = this.seq1[i - 1] + align1;
                align2 = this.seq2[j - 1] + align2;
                i--;
                j--;
            } else if (this.matrix[i - 1][j] > this.matrix[i][j - 1]) {
                align1 = this.seq1[i - 1] + align1;
                align2 = '-' + align2;
                i--;
            } else {
                align1 = '-' + align1;
                align2 = this.seq2[j - 1] + align2;
                j--;
            }
        }
        while (i > 0) {
            align1 = this.seq1[i - 1] + align1;
            align2 = '-' + align2;
            i--;
        }
        while (j > 0) {
            align1 = '-' + align1;
            align2 = this.seq2[j - 1] + align2;
            j--;
        }
        return [align1, align2];
    }
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.build_matrix();
    const [aligned_seq1, aligned_seq2] = aligner.trace_back();
    console.log(`Aligned Sequence 1: ${aligned_seq1}`);
    console.log(`Aligned Sequence 2: ${aligned_seq2}`);
}

main();