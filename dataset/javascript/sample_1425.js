class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.score_matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
        this.trace_matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    fill_matrices() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                let match = this.score_matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : 0);
                let delete = this.score_matrix[i - 1][j] - 1;
                let insert = this.score_matrix[i][j - 1] - 1;
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

    trace_back() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let aligned_seq1 = [];
        let aligned_seq2 = [];
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
    let seq1 = 'AGGTAB';
    let seq2 = 'GXTXAYB';
    let aligner = new SequenceAligner(seq1, seq2);
    aligner.fill_matrices();
    let [aligned_seq1, aligned_seq2] = aligner.trace_back();
    console.log('Aligned Sequence 1:', aligned_seq1);
    console.log('Aligned Sequence 2:', aligned_seq2);
}

main();