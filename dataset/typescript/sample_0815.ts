class GenomicAligner {
    seq1: string;
    seq2: string;
    matrix: number[][];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    _score(a: string, b: string): number {
        return a === b ? 1 : -1;
    }

    _fill_matrix(): void {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const match = this.matrix[i - 1][j - 1] + this._score(this.seq1[i - 1], this.seq2[j - 1]);
                const deleteOp = this.matrix[i - 1][j] - 1;
                const insert = this.matrix[i][j - 1] - 1;
                this.matrix[i][j] = Math.max(match, deleteOp, insert);
            }
        }
    }

    _traceback(i: number, j: number): [string, string] {
        if (i === 0 || j === 0) {
            return ['', ''];
        }
        if (this.matrix[i][j] === this.matrix[i - 1][j - 1] + this._score(this.seq1[i - 1], this.seq2[j - 1])) {
            const [s1, s2] = this._traceback(i - 1, j - 1);
            return [this.seq1[i - 1] + s1, this.seq2[j - 1] + s2];
        } else if (this.matrix[i][j] === this.matrix[i - 1][j] - 1) {
            const [s1, s2] = this._traceback(i - 1, j);
            return [this.seq1[i - 1] + s1, '-' + s2];
        } else {
            const [s1, s2] = this._traceback(i, j - 1);
            return ['-' + s1, this.seq2[j - 1] + s2];
        }
    }

    align(): [string, string] {
        this._fill_matrix();
        return this._traceback(this.seq1.length, this.seq2.length);
    }
}

function main(): void {
    const seq1 = 'ACGTGACGTG';
    const seq2 = 'GTCGTGTCG';
    const aligner = new GenomicAligner(seq1, seq2);
    const [aligned_seq1, aligned_seq2] = aligner.align();
    console.log('Aligned Sequence 1:', aligned_seq1);
    console.log('Aligned Sequence 2:', aligned_seq2);
}

main();