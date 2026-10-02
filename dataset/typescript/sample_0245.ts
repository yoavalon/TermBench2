class GenomicAligner {
    seq1: string;
    seq2: string;
    matrix: number[][];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    _fill_matrix() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                if (this.seq1[i - 1] === this.seq2[j - 1]) {
                    this.matrix[i][j] = this.matrix[i - 1][j - 1] + 1;
                } else {
                    this.matrix[i][j] = Math.max(this.matrix[i - 1][j], this.matrix[i][j - 1]);
                }
            }
        }
    }

    _traceback() {
        const alignment1: string[] = [];
        const alignment2: string[] = [];
        let i = this.seq1.length;
        let j = this.seq2.length;
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                alignment1.push(this.seq1[i - 1]);
                alignment2.push(this.seq2[j - 1]);
                i -= 1;
                j -= 1;
            } else if (this.matrix[i - 1][j] > this.matrix[i][j - 1]) {
                alignment1.push(this.seq1[i - 1]);
                alignment2.push('-');
                i -= 1;
            } else {
                alignment1.push('-');
                alignment2.push(this.seq2[j - 1]);
                j -= 1;
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
    const seq1 = 'AGTACGCA';
    const seq2 = 'TGACGTCA';
    const aligner = new GenomicAligner(seq1, seq2);
    const result = aligner.align();
    console.log('Alignment 1:', result[0].join(''));
    console.log('Alignment 2:', result[1].join(''));
}

main();