class SequenceAligner {
    seq1: string;
    seq2: string;
    match: number;
    mismatch: number;
    gap: number;

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.match = 1;
        this.mismatch = -1;
        this.gap = -2;
    }

    score(x: string, y: string): number {
        return x === y ? this.match : this.mismatch;
    }

    align(): number {
        const m = this.seq1.length;
        const n = this.seq2.length;
        const dp: number[][] = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));

        for (let i = 0; i <= m; i++) {
            for (let j = 0; j <= n; j++) {
                if (i === 0) {
                    dp[i][j] = j * this.gap;
                } else if (j === 0) {
                    dp[i][j] = i * this.gap;
                } else {
                    dp[i][j] = Math.max(
                        dp[i - 1][j - 1] + this.score(this.seq1[i - 1], this.seq2[j - 1]),
                        dp[i - 1][j] + this.gap,
                        dp[i][j - 1] + this.gap
                    );
                }
            }
        }
        return dp[m][n];
    }
}

class Analysis {
    aligner: SequenceAligner;

    constructor(aligner: SequenceAligner) {
        this.aligner = aligner;
    }

    run(): void {
        while (true) {
            const score = this.aligner.align();
            console.log(`Alignment Score: ${score}`);
        }
    }
}

function main(): void {
    const seq1 = 'ACGT';
    const seq2 = 'ACGTC';
    const aligner = new SequenceAligner(seq1, seq2);
    const analysis = new Analysis(aligner);
    analysis.run();
}

main();