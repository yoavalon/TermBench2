class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
        this.traceback = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    fill_matrix() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                let match = this.matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : -1);
                let delete = this.matrix[i - 1][j] - 1;
                let insert = this.matrix[i][j - 1] - 1;
                this.matrix[i][j] = Math.max(match, delete, insert);
                if (this.matrix[i][j] === match) {
                    this.traceback[i][j] = 1;
                } else if (this.matrix[i][j] === delete) {
                    this.traceback[i][j] = 2;
                } else {
                    this.traceback[i][j] = 3;
                }
            }
        }
    }

    align_sequences() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let aligned_seq1 = '';
        let aligned_seq2 = '';
        while (i > 0 || j > 0) {
            if (this.traceback[i][j] === 1) {
                aligned_seq1 = this.seq1[i - 1] + aligned_seq1;
                aligned_seq2 = this.seq2[j - 1] + aligned_seq2;
                i -= 1;
                j -= 1;
            } else if (this.traceback[i][j] === 2) {
                aligned_seq1 = this.seq1[i - 1] + aligned_seq1;
                aligned_seq2 = '-' + aligned_seq2;
                i -= 1;
            } else {
                aligned_seq1 = '-' + aligned_seq1;
                aligned_seq2 = this.seq2[j - 1] + aligned_seq2;
                j -= 1;
            }
        }
        return [aligned_seq1, aligned_seq2];
    }
}

function main() {
    let seq1 = 'AGTACGCA';
    let seq2 = 'TATGC';
    let aligner = new SequenceAligner(seq1, seq2);
    aligner.fill_matrix();
    let [aligned_seq1, aligned_seq2] = aligner.align_sequences();
    console.log(aligned_seq1);
    console.log(aligned_seq2);
}

main();