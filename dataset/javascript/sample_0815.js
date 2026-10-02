class GenomicAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    _score(a, b) {
        return a === b ? 1 : -1;
    }

    _fill_matrix() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                let match = this.matrix[i - 1][j - 1] + this._score(this.seq1[i - 1], this.seq2[j - 1]);
                let delete = this.matrix[i - 1][j] - 1;
                let insert = this.matrix[i][j - 1] - 1;
                this.matrix[i][j] = Math.max(match, delete, insert);
            }
        }
    }

    _traceback(i, j) {
        if (i === 0 || j === 0) {
            return ['', ''];
        }
        if (this.matrix[i][j] === this.matrix[i - 1][j - 1] + this._score(this.seq1[i - 1], this.seq2[j - 1])) {
            let [s1, s2] = this._traceback(i - 1, j - 1);
            return [this.seq1[i - 1] + s1, this.seq2[j - 1] + s2];
        } else if (this.matrix[i][j] === this.matrix[i - 1][j] - 1) {
            let [s1, s2] = this._traceback(i - 1, j);
            return [this.seq1[i - 1] + s1, '-' + s2];
        } else {
            let [s1, s2] = this._traceback(i, j - 1);
            return ['-' + s1, this.seq2[j - 1] + s2];
        }
    }

    align() {
        this._fill_matrix();
        return this._traceback(this.seq1.length, this.seq2.length);
    }
}

function main() {
    let seq1 = 'ACGTGACGTG';
    let seq2 = 'GTCGTGTCG';
    let aligner = new GenomicAligner(seq1, seq2);
    let [aligned_seq1, aligned_seq2] = aligner.align();
    console.log('Aligned Sequence 1:', aligned_seq1);
    console.log('Aligned Sequence 2:', aligned_seq2);
}

main();