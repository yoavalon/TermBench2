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
                this.matrix[i][j] = Math.max(this.matrix[i - 1][j], this.matrix[i][j - 1], match);
            }
        }
    }

    traceback() {
        let aligned_seq1 = [];
        let aligned_seq2 = [];
        let i = this.seq1.length;
        let j = this.seq2.length;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && (this.seq1[i - 1] === this.seq2[j - 1])) {
                aligned_seq1.push(this.seq1[i - 1]);
                aligned_seq2.push(this.seq2[j - 1]);
                i -= 1;
                j -= 1;
            } else if (i > 0 && this.matrix[i][j] === this.matrix[i - 1][j]) {
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
    let seq1 = 'AGGTAB';
    let seq2 = 'GXTXAYB';
    let aligner = new SequenceAligner(seq1, seq2);
    aligner.fill_matrix();
    let [aligned_seq1, aligned_seq2] = aligner.traceback();
    console.log(aligned_seq1);
    console.log(aligned_seq2);
}

main();