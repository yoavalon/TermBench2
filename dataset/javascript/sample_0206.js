class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    }

    initialize_matrix() {
        for (let i = 0; i <= this.seq1.length; i++) {
            this.matrix[i][0] = i;
        }
        for (let j = 0; j <= this.seq2.length; j++) {
            this.matrix[0][j] = j;
        }
    }

    compute_similarity() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                let match = this.matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : 0);
                let delete = this.matrix[i - 1][j] + 1;
                let insert = this.matrix[i][j - 1] + 1;
                this.matrix[i][j] = Math.min(match, delete, insert);
            }
        }
    }

    trace_back() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let aligned_seq1 = [];
        let aligned_seq2 = [];
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && this.matrix[i][j] === this.matrix[i - 1][j - 1] + (this.seq1[i - 1] === this.seq2[j - 1] ? 1 : 0)) {
                aligned_seq1.push(this.seq1[i - 1]);
                aligned_seq2.push(this.seq2[j - 1]);
                i -= 1;
                j -= 1;
            } else if (i > 0 && this.matrix[i][j] === this.matrix[i - 1][j] + 1) {
                aligned_seq1.push(this.seq1[i - 1]);
                aligned_seq2.push('-');
                i -= 1;
            } else {
                aligned_seq1.push('-');
                aligned_seq2.push(this.seq2[j - 1]);
                j -= 1;
            }
        }
        return [aligned_seq1.reverse().join(''), aligned_seq2.reverse().join('')];
    }
}

function main() {
    let seq1 = 'AGGTAB';
    let seq2 = 'GXTXAYB';
    let aligner = new SequenceAligner(seq1, seq2);
    aligner.initialize_matrix();
    aligner.compute_similarity();
    let [aligned_seq1, aligned_seq2] = aligner.trace_back();
    console.log('Aligned Sequence 1:', aligned_seq1);
    console.log('Aligned Sequence 2:', aligned_seq2);
}

main();