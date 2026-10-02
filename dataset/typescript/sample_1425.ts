class SequenceAligner {
    seq1: string;
    seq2: string;
    score_matrix: number[][];
    trace_matrix: number[][];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.score_matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
        this.trace_matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    fill_matrices() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const match = this.score_matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : 0);
                const delete = this.score_matrix[i - 1][j] - 1;
                const insert = this.score_matrix[i][j - 1] - 1;
                this.score_matrix[i][j] = Math.max(match, delete, insert);
                if (this.score_matrix[i][j] === match) {
                    this.trace_matrix[i][j] = 1;
                } else if (this.score_matrix[i][j] === delete) {
                    this.trace_matrix[i][j] = 2;
                } else {
                    this.trace_matrix[i][j] = 3;
                }
            }
        }
    }

    trace_back(): [string, string] {
        let i = this.seq1.length;
        let j = this.seq2.length;
        const aligned_seq1: string[] = [];
        const aligned_seq2: string[] = [];
        while (i > 0 && j > 0) {
            if (this.trace_matrix[i][j] === 1) {
                aligned_seq1.push(this.seq1[i - 1]);
                aligned_seq2.push(this.seq2[j - 1]);
                i -= 1;
                j -= 1;
            } else if (this.trace_matrix[i][j] === 2) {
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
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.fill_matrices();
    const [aligned_seq1, aligned_seq2] = aligner.trace_back();
    console.log('Aligned Sequence 1:', aligned_seq1);
    console.log('Aligned Sequence 2:', aligned_seq2);
}

main();