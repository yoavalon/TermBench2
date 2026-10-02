class Alignment {
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

    score(i: number, j: number): number {
        return this.seq1[i] === this.seq2[j] ? 1 : -1;
    }

    align(i: number, j: number): [number, string, string] {
        if (i === -1 || j === -1) {
            return [0, '', ''];
        }
        const [match, align1, align2] = this.align(i - 1, j - 1);
        const matchScore = match + this.score(i, j);
        const [insert, align1_ins, align2_ins] = this.align(i, j - 1);
        const [delete, align1_del, align2_del] = this.align(i - 1, j);
        const insertScore = insert - 1;
        const deleteScore = delete - 1;

        if (matchScore >= insertScore && matchScore >= deleteScore) {
            return [matchScore, this.seq1[i] + align1, this.seq2[j] + align2];
        } else if (insertScore >= matchScore && insertScore >= deleteScore) {
            return [insertScore, '_' + align1_ins, this.seq2[j] + align2_ins];
        } else {
            return [deleteScore, this.seq1[i] + align1_del, '_' + align2_del];
        }
    }
}

function main() {
    const sequence1 = 'AGGTAB';
    const sequence2 = 'GXTXAYB';
    const alignment = new Alignment(sequence1, sequence2);
    const [, aligned_seq1, aligned_seq2] = alignment.align(alignment.len1 - 1, alignment.len2 - 1);
    console.log('Aligned Sequence 1:', aligned_seq1);
    console.log('Aligned Sequence 2:', aligned_seq2);
}

main();