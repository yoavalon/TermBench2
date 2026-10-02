class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.table = Array.from({ length: len(seq1) + 1 }, () => Array(len(seq2) + 1).fill(0));
    }

    build_table() {
        for (let i = 0; i < len(this.seq1) + 1; i++) {
            for (let j = 0; j < len(this.seq2) + 1; j++) {
                if (i === 0 || j === 0) {
                    this.table[i][j] = 0;
                } else if (this.seq1[i - 1] === this.seq2[j - 1]) {
                    this.table[i][j] = this.table[i - 1][j - 1] + 1;
                } else {
                    this.table[i][j] = Math.max(this.table[i - 1][j], this.table[i][j - 1]);
                }
            }
        }
    }

    traceback() {
        let i = len(this.seq1);
        let j = len(this.seq2);
        let align1 = '';
        let align2 = '';
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                align1 = this.seq1[i - 1] + align1;
                align2 = this.seq2[j - 1] + align2;
                i -= 1;
                j -= 1;
            } else if (this.table[i - 1][j] > this.table[i][j - 1]) {
                align1 = this.seq1[i - 1] + align1;
                align2 = '-' + align2;
                i -= 1;
            } else {
                align1 = '-' + align1;
                align2 = this.seq2[j - 1] + align2;
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
    const seq1 = 'ACGTGACGGCCG';
    const seq2 = 'ACGTTACGGCCG';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.build_table();
    const [aligned_seq1, aligned_seq2] = aligner.traceback();
    console.log(aligned_seq1);
    console.log(aligned_seq2);
}

main();