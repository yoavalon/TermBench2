class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    calculate_matrix() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                let match = this.matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : -1);
                let delete = this.matrix[i - 1][j] - 1;
                let insert = this.matrix[i][j - 1] - 1;
                this.matrix[i][j] = Math.max(match, delete, insert);
            }
        }
    }

    traceback() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let align1 = '';
        let align2 = '';
        while (i > 0 && j > 0) {
            if (this.matrix[i][j] === this.matrix[i - 1][j] - 1) {
                align1 = this.seq1[i - 1] + align1;
                align2 = '-' + align2;
                i -= 1;
            } else if (this.matrix[i][j] === this.matrix[i][j - 1] - 1) {
                align1 = '-' + align1;
                align2 = this.seq2[j - 1] + align2;
                j -= 1;
            } else {
                align1 = this.seq1[i - 1] + align1;
                align2 = this.seq2[j - 1] + align2;
                i -= 1;
                j -= 1;
            }
        }
        while (i > 0) {
            align1 = this.seq1[i - 1] + align1;
            align2 = '-' + align2;
            i -= 1;
        }
        while (j > 0) {
            align1 = '-' + align1;
            align2 = this.seq2[j - 1] + align2;
            j -= 1;
        }
        return [align1, align2];
    }
}

function main() {
    let seq1 = 'ACCGGTCGAGTGCGCGGAAGCCGGCCGAA';
    let seq2 = 'GTCGTTCGGAATGCCGTTGCTCTGTAAA';
    let aligner = new SequenceAligner(seq1, seq2);
    aligner.calculate_matrix();
    let [aligned_seq1, aligned_seq2] = aligner.traceback();
    console.log('Aligned Sequence 1:', aligned_seq1);
    console.log('Aligned Sequence 2:', aligned_seq2);
}

main();