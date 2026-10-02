class SequenceAligner {
    seq1: string;
    seq2: string;
    matrix: number[][] | null;

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = null;
    }

    create_matrix() {
        this.matrix = Array.from({ length: this.seq1.length + 1 }, () => Array(this.seq2.length + 1).fill(0));
    }

    fill_matrix() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const match = this.matrix![i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : 0);
                const deleteOp = this.matrix![i - 1][j] - 1;
                const insertOp = this.matrix![i][j - 1] - 1;
                this.matrix![i][j] = Math.max(match, deleteOp, insertOp);
            }
        }
    }

    trace_back() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        const align1: string[] = [];
        const align2: string[] = [];
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                align1.push(this.seq1[i - 1]);
                align2.push(this.seq2[j - 1]);
                i -= 1;
                j -= 1;
            } else if (this.matrix![i - 1][j] > this.matrix![i][j - 1]) {
                align1.push(this.seq1[i - 1]);
                align2.push('-');
                i -= 1;
            } else {
                align1.push('-');
                align2.push(this.seq2[j - 1]);
                j -= 1;
            }
        }
        while (i > 0) {
            align1.push(this.seq1[i - 1]);
            align2.push('-');
            i -= 1;
        }
        while (j > 0) {
            align1.push('-');
            align2.push(this.seq2[j - 1]);
            j -= 1;
        }
        return [align1.reverse().join(''), align2.reverse().join('')];
    }
}

function main() {
    const seq1 = 'GATTACA';
    const seq2 = 'GCATGCU';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.create_matrix();
    aligner.fill_matrix();
    const [aligned_seq1, aligned_seq2] = aligner.trace_back();
    console.log(aligned_seq1);
    console.log(aligned_seq2);
}

main();