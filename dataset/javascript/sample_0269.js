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

    fill_matrix() {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                let cost = this.seq1[i - 1] === this.seq2[j - 1] ? 0 : 1;
                this.matrix[i][j] = Math.min(
                    this.matrix[i - 1][j] + 1,
                    this.matrix[i][j - 1] + 1,
                    this.matrix[i - 1][j - 1] + cost
                );
            }
        }
    }

    trace_back() {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let align1 = '';
        let align2 = '';
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && this.seq1[i - 1] === this.seq2[j - 1]) {
                align1 = this.seq1[i - 1] + align1;
                align2 = this.seq2[j - 1] + align2;
                i--;
                j--;
            } else if (i > 0 && this.matrix[i][j] === this.matrix[i - 1][j] + 1) {
                align1 = this.seq1[i - 1] + align1;
                align2 = '-' + align2;
                i--;
            } else {
                align1 = '-' + align1;
                align2 = this.seq2[j - 1] + align2;
                j--;
            }
        }
        return [align1, align2];
    }
}

function main() {
    let seq1 = 'AGGTAB';
    let seq2 = 'GXTXAYB';
    let aligner = new SequenceAligner(seq1, seq2);
    aligner.initialize_matrix();
    aligner.fill_matrix();
    let aligned_sequences = aligner.trace_back();
    console.log('Aligned Sequence 1:', aligned_sequences[0]);
    console.log('Aligned Sequence 2:', aligned_sequences[1]);
}

main();