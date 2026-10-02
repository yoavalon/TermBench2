class SequenceAligner {
    seq1: string;
    seq2: string;
    matrix: number[][] | null;

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.matrix = null;
    }

    initialize_matrix(): void {
        const len1 = this.seq1.length;
        const len2 = this.seq2.length;
        this.matrix = Array.from({ length: len1 + 1 }, () => Array(len2 + 1).fill(0));
        for (let i = 0; i <= len1; i++) {
            this.matrix[i][0] = i;
        }
        for (let j = 0; j <= len2; j++) {
            this.matrix[0][j] = j;
        }
    }

    compute_alignment(): void {
        for (let i = 1; i <= this.seq1.length; i++) {
            for (let j = 1; j <= this.seq2.length; j++) {
                const cost = this.seq1[i - 1] === this.seq2[j - 1] ? 0 : 1;
                this.matrix[i][j] = Math.min(
                    this.matrix[i - 1][j] + 1,
                    this.matrix[i][j - 1] + 1,
                    this.matrix[i - 1][j - 1] + cost
                );
            }
        }
    }

    backtrack_alignment(): [string, string] {
        let i = this.seq1.length;
        let j = this.seq2.length;
        let align1 = '';
        let align2 = '';
        while (i > 0 && j > 0) {
            if (this.seq1[i - 1] === this.seq2[j - 1]) {
                align1 = this.seq1[i - 1] + align1;
                align2 = this.seq2[j - 1] + align2;
                i -= 1;
                j -= 1;
            } else if (this.matrix![i - 1][j] + 1 === this.matrix![i][j]) {
                align1 = this.seq1[i - 1] + align1;
                align2 = '-' + align2;
                i -= 1;
            } else {
                align1 = '-' + align1;
                align2 = this.seq2[j - 1] + align2;
                j -= 1;
            }
        }
        while (i > 0) {
            align1 = this.seq1[i - 1] + align1;
            align2 = '-' + align2;
            i -= 1;
        }
        while (j > 0) {
            align1 = '-' + align1;
            align2 = this.seq2[j - 1] + align2;
            j -= 1;
        }
        return [align1, align2];
    }
}

function main(): void {
    const seq1 = 'ACCGGTCGAGTGCGCGGAAGCCGGCCGAA';
    const seq2 = 'GTCGTTCGGAATGCCGTTGCTCTGTAAA';
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.initialize_matrix();
    aligner.compute_alignment();
    const alignment = aligner.backtrack_alignment();
    console.log('Aligned Sequence 1:', alignment[0]);
    console.log('Aligned Sequence 2:', alignment[1]);
}

main();