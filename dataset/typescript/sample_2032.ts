class SequenceAligner {
    seq1: string;
    seq2: string;
    matrix: number[][];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    compute_score(a: string, b: string): number {
        return a === b ? 1 : -1;
    }

    fill_matrix(): void {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const match = this.matrix[i - 1][j - 1] + this.compute_score(this.seq1[i - 1], this.seq2[j - 1]);
                const deleteOp = this.matrix[i - 1][j] - 1;
                const insert = this.matrix[i][j - 1] - 1;
                this.matrix[i][j] = Math.max(match, deleteOp, insert);
            }
        }
    }

    trace_back(): [string, string] {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let align1 = '';
        let align2 = '';

        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && this.matrix[i][j] === this.matrix[i - 1][j - 1] + this.compute_score(this.seq1[i - 1], this.seq2[j - 1])) {
                align1 = this.seq1[i - 1] + align1;
                align2 = this.seq2[j - 1] + align2;
                i -= 1;
                j -= 1;
            } else if (i > 0 && this.matrix[i][j] === this.matrix[i - 1][j] - 1) {
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

function main(): void {
    const seq1 = 'ACGT';
    const seq2 = 'ACGTA';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.fill_matrix();
    const aligned_sequences = aligner.trace_back();
    console.log('Aligned Sequence 1:', aligned_sequences[0]);
    console.log('Aligned Sequence 2:', aligned_sequences[1]);
}

main();