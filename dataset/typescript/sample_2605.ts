class SequenceMatcher {
    seq1: string;
    seq2: string;
    len1: number;
    len2: number;

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
        this.len1 = seq1.length;
        this.len2 = seq2.length;
    }

    match(): number {
        const matrix: number[][] = Array.from({ length: this.len1 + 1 }, () => Array(this.len2 + 1).fill(0));
        for (let i = 1; i <= this.len1; i++) {
            for (let j = 1; j <= this.len2; j++) {
                if (this.seq1[i - 1] === this.seq2[j - 1]) {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1;
                } else {
                    matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
                }
            }
        }
        return matrix[this.len1][this.len2];
    }
}

class GenomicSequenceAnalyzer {
    sequences: string[];

    constructor(sequences: string[]) {
        this.sequences = sequences;
    }

    analyze(): [number, number, number][] {
        const results: [number, number, number][] = [];
        for (let i = 0; i < this.sequences.length; i++) {
            for (let j = i + 1; j < this.sequences.length; j++) {
                const matcher = new SequenceMatcher(this.sequences[i], this.sequences[j]);
                results.push([i, j, matcher.match()]);
            }
        }
        return results;
    }
}

function main() {
    const sequences = ['ATCGTACG', 'CGTACGTA', 'GTAATCGC', 'TACGTACG', 'ACGTACGT'];
    const analyzer = new GenomicSequenceAnalyzer(sequences);
    const results = analyzer.analyze();
    for (const [idx1, idx2, score] of results) {
        console.log(`Sequence ${idx1} vs Sequence ${idx2}: Alignment Score ${score}`);
    }
}

main();