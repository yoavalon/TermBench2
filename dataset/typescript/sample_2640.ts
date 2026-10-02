class SequenceAligner {
    seq1: string;
    seq2: string;
    m: number;
    n: number;
    dp: number[][];

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.m = seq1.length;
        this.n = seq2.length;
        this.dp = Array.from({ length: this.m + 1 }, () => Array(this.n + 1).fill(0));
    }

    calculate_score() {
        for (let i = 1; i <= this.m; i++) {
            for (let j = 1; j <= this.n; j++) {
                if (this.seq1[i - 1] === this.seq2[j - 1]) {
                    this.dp[i][j] = this.dp[i - 1][j - 1] + 1;
                } else {
                    this.dp[i][j] = Math.max(this.dp[i - 1][j], this.dp[i][j - 1]);
                }
            }
        }
    }

    traceback() {
        let i = this.m;
        let j = this.n;
        let align1 = '';
        let align2 = '';
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && this.seq1[i - 1] === this.seq2[j - 1]) {
                align1 = this.seq1[i - 1] + align1;
                align2 = this.seq2[j - 1] + align2;
                i -= 1;
                j -= 1;
            } else if (i > 0 && this.dp[i][j] === this.dp[i - 1][j]) {
                align1 = this.seq1[i - 1] + align1;
                align2 = '-' + align2;
                i -= 1;
            } else {
                align1 = '-' + align1;
                align2 = this.seq2[j - 1] + align2;
                j -= 1;
            }
        }
        return [align1, align2];
    }
}

function main() {
    const seq1 = 'AGGTAB';
    const seq2 = 'GXTXAYB';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.calculate_score();
    const result = aligner.traceback();
    console.log('Aligned Sequence 1:', result[0]);
    console.log('Aligned Sequence 2:', result[1]);
}

main();