class SequenceAligner {
    seq1: string;
    seq2: string;
    matrix: number[][];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    fill_matrix(): void {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const match = this.seq1[i - 1] === this.seq2[j - 1] ? this.matrix[i - 1][j - 1] + 1 : 0;
                const deleteOp = this.matrix[i - 1][j] - 1;
                const insert = this.matrix[i][j - 1] - 1;
                this.matrix[i][j] = Math.max(match, deleteOp, insert);
            }
        }
    }

    trace_back(): [string, string] {
        let i = this.seq1.length;
        let j = this.seq2.length;
        const aligned_seq1: string[] = [];
        const aligned_seq2: string[] = [];
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                aligned_seq1.push(this.seq1[i - 1]);
                aligned_seq2.push(this.seq2[j - 1]);
                i -= 1;
                j -= 1;
            } else if (this.matrix[i - 1][j] > this.matrix[i][j - 1]) {
                aligned_seq1.push(this.seq1[i - 1]);
                aligned_seq2.push('-');
                i -= 1;
            } else {
                aligned_seq1.push('-');
                aligned_seq2.push(this.seq2[j - 1]);
                j -= 1;
            }
        }
        aligned_seq1.reverse();
        aligned_seq2.reverse();
        return [aligned_seq1.join(''), aligned_seq2.join('')];
    }
}

function main() {
    const seq1 = 'GATTACA';
    const seq2 = 'CGATACG';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.fill_matrix();
    const [result1, result2] = aligner.trace_back();
    console.log(result1);
    console.log(result2);
}

main();