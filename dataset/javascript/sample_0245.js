class GenomicAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: len(seq1) + 1 }, () => Array(len(seq2) + 1).fill(0));
    }

    _fill_matrix() {
        for (let i = 1; i <= len(this.seq1); i++) {
            for (let j = 1; j <= len(this.seq2); j++) {
                if (this.seq1[i - 1] === this.seq2[j - 1]) {
                    this.matrix[i][j] = this.matrix[i - 1][j - 1] + 1;
                } else {
                    this.matrix[i][j] = Math.max(this.matrix[i - 1][j], this.matrix[i][j - 1]);
                }
            }
        }
    }

    _traceback() {
        let alignment1 = [];
        let alignment2 = [];
        let i = len(this.seq1);
        let j = len(this.seq2);
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                alignment1.push(this.seq1[i - 1]);
                alignment2.push(this.seq2[j - 1]);
                i--;
                j--;
            } else if (this.matrix[i - 1][j] > this.matrix[i][j - 1]) {
                alignment1.push(this.seq1[i - 1]);
                alignment2.push('-');
                i--;
            } else {
                alignment1.push('-');
                alignment2.push(this.seq2[j - 1]);
                j--;
            }
        }
        alignment1.reverse();
        alignment2.reverse();
        return [alignment1, alignment2];
    }

    align() {
        this._fill_matrix();
        return this._traceback();
    }
}

function main() {
    let seq1 = 'AGTACGCA';
    let seq2 = 'TGACGTCA';
    let aligner = new GenomicAligner(seq1, seq2);
    let result = aligner.align();
    console.log('Alignment 1:', result[0].join(''));
    console.log('Alignment 2:', result[1].join(''));
}

main();