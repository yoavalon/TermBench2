class SequenceAligner {
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.m = seq1.length;
        this.n = seq2.length;
        this.dp = Array.from({ length: this.m + 1 }, () => Array(this.n + 1).fill(0));
    }

    compute_alignment() {
        for (let i = 0; i <= this.m; i++) {
            for (let j = 0; j <= this.n; j++) {
                if (i === 0) {
                    this.dp[i][j] = j;
                } else if (j === 0) {
                    this.dp[i][j] = i;
                } else if (this.seq1[i - 1] === this.seq2[j - 1]) {
                    this.dp[i][j] = this.dp[i - 1][j - 1];
                } else {
                    this.dp[i][j] = 1 + Math.min(this.dp[i][j - 1], this.dp[i - 1][j], this.dp[i - 1][j - 1]);
                }
            }
        }
    }

    get_alignment() {
        let alignment1 = '';
        let alignment2 = '';
        let i = this.m;
        let j = this.n;
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                alignment1 = this.seq1[i - 1] + alignment1;
                alignment2 = this.seq2[j - 1] + alignment2;
                i -= 1;
                j -= 1;
            } else if (this.dp[i - 1][j] < this.dp[i][j - 1] && this.dp[i - 1][j] < this.dp[i - 1][j - 1]) {
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

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.compute_alignment();
    const [alignment1, alignment2] = aligner.get_alignment();
    console.log('Alignment 1:', alignment1);
    console.log('Alignment 2:', alignment2);
}

main();