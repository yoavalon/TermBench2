class SequenceMatcher {
    seq1: string;
    seq2: string;
    matrix: number[][];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    compute_alignment(): void {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const match = this.seq1[i - 1] === this.seq2[j - 1] ? this.matrix[i - 1][j - 1] + 1 : 0;
                const deleteOp = this.matrix[i - 1][j];
                const insert = this.matrix[i][j - 1];
                this.matrix[i][j] = Math.max(match, deleteOp, insert);
            }
        }
    }

    trace_back(): [string, string] {
        let alignment1 = '';
        let alignment2 = '';
        let i = this.seq1.length;
        let j = this.seq2.length;
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                alignment1 = this.seq1[i - 1] + alignment1;
                alignment2 = this.seq2[j - 1] + alignment2;
                i--;
                j--;
            } else if (this.matrix[i - 1][j] >= this.matrix[i][j - 1]) {
                alignment1 = this.seq1[i - 1] + alignment1;
                alignment2 = '-' + alignment2;
                i--;
            } else {
                alignment1 = '-' + alignment1;
                alignment2 = this.seq2[j - 1] + alignment2;
                j--;
            }
        }
        while (i > 0) {
            alignment1 = this.seq1[i - 1] + alignment1;
            alignment2 = '-' + alignment2;
            i--;
        }
        while (j > 0) {
            alignment1 = '-' + alignment1;
            alignment2 = this.seq2[j - 1] + alignment2;
            j--;
        }
        return [alignment1, alignment2];
    }
}

function process_sequences(seq1: string, seq2: string): [string, string] {
    const matcher = new SequenceMatcher(seq1, seq2);
    matcher.compute_alignment();
    return matcher.trace_back();
}

function main(): void {
    const seq1 = 'AGCTG';
    const seq2 = 'AGGCT';
    const [aligned_seq1, aligned_seq2] = process_sequences(seq1, seq2);
    console.log(aligned_seq1);
    console.log(aligned_seq2);
}

main();