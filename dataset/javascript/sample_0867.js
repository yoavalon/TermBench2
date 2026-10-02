class Alignment {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
        this.fillMatrix();
        this.traceback();
    }

    fillMatrix() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const match = (this.seq1[i - 1] === this.seq2[j - 1]) ? this.matrix[i - 1][j - 1] + 1 : 0;
                const deleteOp = this.matrix[i - 1][j] - 1;
                const insert = this.matrix[i][j - 1] - 1;
                this.matrix[i][j] = Math.max(match, deleteOp, insert);
            }
        }
    }

    traceback() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let align1 = '';
        let align2 = '';
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && (this.matrix[i][j] === this.matrix[i - 1][j - 1] + 1) && (this.seq1[i - 1] === this.seq2[j - 1])) {
                align1 = this.seq1[i - 1] + align1;
                align2 = this.seq2[j - 1] + align2;
                i -= 1;
                j -= 1;
            } else if (i > 0 && (j === 0 || this.matrix[i][j] === this.matrix[i - 1][j] - 1)) {
                align1 = this.seq1[i - 1] + align1;
                align2 = '-' + align2;
                i -= 1;
            } else {
                align1 = '-' + align1;
                align2 = this.seq2[j - 1] + align2;
                j -= 1;
            }
        }
        this.result = [align1, align2];
    }
}

function main() {
    const seq1 = 'AGTACGCA';
    const seq2 = 'GTTAC';
    const alignment = new Alignment(seq1, seq2);
    console.log('Sequence 1:', alignment.result[0]);
    console.log('Sequence 2:', alignment.result[1]);
}

main();