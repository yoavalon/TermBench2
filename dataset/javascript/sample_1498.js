class SequenceMatcher {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    compute_alignment() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                let match = this.matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : 0);
                let delete = this.matrix[i - 1][j];
                let insert = this.matrix[i][j - 1];
                this.matrix[i][j] = Math.max(match, delete, insert);
            }
        }
    }

    trace_back() {
        let alignment1 = '';
        let alignment2 = '';
        let i = this.seq1.length;
        let j = this.seq2.length;
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                alignment1 = this.seq1[i - 1] + alignment1;
                alignment2 = this.seq2[j - 1] + alignment2;
                i -= 1;
                j -= 1;
            } else if (this.matrix[i - 1][j] >= this.matrix[i][j - 1]) {
                alignment1 = this.seq1[i - 1] + alignment1;
                alignment2 = '-' + alignment2;
                i -= 1;
            } else {
                alignment1 = '-' + alignment1;
                alignment2 = this.seq2[j - 1] + alignment2;
                j -= 1;
            }
        }
        while (i > 0) {
            alignment1 = this.seq1[i - 1] + alignment1;
            alignment2 = '-' + alignment2;
            i -= 1;
        }
        while (j > 0) {
            alignment1 = '-' + alignment1;
            alignment2 = this.seq2[j - 1] + alignment2;
            j -= 1;
        }
        return [alignment1, alignment2];
    }
}

function process_sequences(seq1, seq2) {
    let matcher = new SequenceMatcher(seq1, seq2);
    matcher.compute_alignment();
    return matcher.trace_back();
}

function main() {
    let seq1 = 'AGCTG';
    let seq2 = 'AGGCT';
    let [aligned_seq1, aligned_seq2] = process_sequences(seq1, seq2);
    console.log(aligned_seq1);
    console.log(aligned_seq2);
}

main();