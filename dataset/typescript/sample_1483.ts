class SequenceAligner {
    seq1: string;
    seq2: string;
    score_matrix: number[][];
    traceback_matrix: number[][];
    max_score: number;
    max_position: [number, number];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.score_matrix = [];
        this.traceback_matrix = [];
        this.max_score = 0;
        this.max_position = [0, 0];
    }

    initialize_matrices() {
        const len1 = this.seq1.length;
        const len2 = this.seq2.length;
        for (let i = 0; i <= len1; i++) {
            this.score_matrix[i] = new Array(len2 + 1).fill(0);
            this.traceback_matrix[i] = new Array(len2 + 1).fill(0);
        }
    }

    fill_matrices() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const match = this.score_matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : -1);
                const delete_op = this.score_matrix[i - 1][j] - 1;
                const insert = this.score_matrix[i][j - 1] - 1;
                this.score_matrix[i][j] = Math.max(match, delete_op, insert);
                if (this.score_matrix[i][j] === match) {
                    this.traceback_matrix[i][j] = 1;
                } else if (this.score_matrix[i][j] === delete_op) {
                    this.traceback_matrix[i][j] = 2;
                } else {
                    this.traceback_matrix[i][j] = 3;
                }
                if (this.score_matrix[i][j] > this.max_score) {
                    this.max_score = this.score_matrix[i][j];
                    this.max_position = [i, j];
                }
            }
        }
    }

    backtrack(): [string, string] {
        const aligned_seq1: string[] = [];
        const aligned_seq2: string[] = [];
        let [i, j] = this.max_position;
        while (i > 0 && j > 0) {
            if (this.traceback_matrix[i][j] === 1) {
                aligned_seq1.push(this.seq1[i - 1]);
                aligned_seq2.push(this.seq2[j - 1]);
                i -= 1;
                j -= 1;
            } else if (this.traceback_matrix[i][j] === 2) {
                aligned_seq1.push(this.seq1[i - 1]);
                aligned_seq2.push('-');
                i -= 1;
            } else {
                aligned_seq1.push('-');
                aligned_seq2.push(this.seq2[j - 1]);
                j -= 1;
            }
        }
        return [aligned_seq1.reverse().join(''), aligned_seq2.reverse().join('')];
    }
}

function main() {
    const seq1 = 'AGCTG';
    const seq2 = 'CGTAT';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.initialize_matrices();
    aligner.fill_matrices();
    const [aligned_seq1, aligned_seq2] = aligner.backtrack();
    console.log(aligned_seq1);
    console.log(aligned_seq2);
}

main();