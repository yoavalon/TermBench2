class SequenceAligner {
    seq1: string;
    seq2: string;
    matrix: number[][];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    fill_matrix() {
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

    trace_back() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let alignment: string[] = [];
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                alignment.push(this.seq1[i - 1]);
                i -= 1;
                j -= 1;
            } else if (this.matrix[i - 1][j] > this.matrix[i][j - 1]) {
                i -= 1;
            } else {
                j -= 1;
            }
        }
        alignment.reverse();
        return alignment.join('');
    }
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.fill_matrix();
    const result = aligner.trace_back();
    console.log('Aligned sequence:', result);
}

main();