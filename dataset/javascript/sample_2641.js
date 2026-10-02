class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    fill_matrix() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                let match = (this.seq1[i - 1] === this.seq2[j - 1]) ? this.matrix[i - 1][j - 1] + 1 : 0;
                let deleteOp = this.matrix[i - 1][j] - 1;
                let insert = this.matrix[i][j - 1] - 1;
                this.matrix[i][j] = Math.max(match, deleteOp, insert);
            }
        }
    }

    trace_back() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let aligned_seq1 = [];
        let aligned_seq2 = [];
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                aligned_seq1.push(this.seq1[i - 1]);
                aligned_seq2.push(this.seq2[j - 1]);
                i--;
                j--;
            } else if (this.matrix[i - 1][j] > this.matrix[i][j - 1]) {
                aligned_seq1.push(this.seq1[i - 1]);
                aligned_seq2.push('-');
                i--;
            } else {
                aligned_seq1.push('-');
                aligned_seq2.push(this.seq2[j - 1]);
                j--;
            }
        }
        aligned_seq1.reverse();
        aligned_seq2.reverse();
        return [aligned_seq1.join(''), aligned_seq2.join('')];
    }
}

function main() {
    let seq1 = 'GATTACA';
    let seq2 = 'CGATACG';
    let aligner = new SequenceAligner(seq1, seq2);
    aligner.fill_matrix();
    let [result1, result2] = aligner.trace_back();
    console.log(result1);
    console.log(result2);
}

main();