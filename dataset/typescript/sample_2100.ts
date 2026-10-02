class SequenceAligner {
    seq1: string;
    seq2: string;
    matrix: number[][];
    traceback_matrix: number[][];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = [];
        this.traceback_matrix = [];
    }

    initialize_matrices() {
        const m = this.seq1.length + 1;
        const n = this.seq2.length + 1;
        this.matrix = Array.from({ length: m }, () => Array(n).fill(0));
        this.traceback_matrix = Array.from({ length: m }, () => Array(n).fill(0));
        for (let i = 1; i < m; i++) {
            this.matrix[i][0] = i;
            this.traceback_matrix[i][0] = 1;
        }
        for (let j = 1; j < n; j++) {
            this.matrix[0][j] = j;
            this.traceback_matrix[0][j] = 2;
        }
    }

    fill_matrices() {
        const m = this.seq1.length;
        const n = this.seq2.length;
        for (let i = 1; i <= m; i++) {
            for (let j = 1; j <= n; j++) {
                const match = this.matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 0 : 1);
                const delete = this.matrix[i - 1][j] + 1;
                const insert = this.matrix[i][j - 1] + 1;
                this.matrix[i][j] = Math.min(match, delete, insert);
                if (this.matrix[i][j] === match) {
                    this.traceback_matrix[i][j] = 3;
                } else if (this.matrix[i][j] === delete) {
                    this.traceback_matrix[i][j] = 1;
                } else {
                    this.traceback_matrix[i][j] = 2;
                }
            }
        }
    }

    traceback() {
        let alignment1 = '';
        let alignment2 = '';
        let i = this.seq1.length;
        let j = this.seq2.length;
        while (i > 0 || j > 0) {
            if (this.traceback_matrix[i][j] === 3) {
                alignment1 = this.seq1[i - 1] + alignment1;
                alignment2 = this.seq2[j - 1] + alignment2;
                i -= 1;
                j -= 1;
            } else if (this.traceback_matrix[i][j] === 1) {
                alignment1 = this.seq1[i - 1] + alignment1;
                alignment2 = '-' + alignment2;
                i -= 1;
            } else {
                alignment1 = '-' + alignment1;
                alignment2 = this.seq2[j - 1] + alignment2;
                j -= 1;
            }
        }
        return [alignment1, alignment2];
    }
}

function main() {
    const seq1 = 'GATTACA';
    const seq2 = 'GCATGCU';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.initialize_matrices();
    aligner.fill_matrices();
    const [alignment1, alignment2] = aligner.traceback();
    console.log(alignment1);
    console.log(alignment2);
}

main();