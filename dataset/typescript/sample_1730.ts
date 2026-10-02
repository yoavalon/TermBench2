function generate_sequence(length: number): string {
    const random = require('random');
    return Array.from({ length }, () => random.choice('ATCG')).join('');
}

function align_sequences(seq1: string, seq2: string): number {
    const matrix: number[][] = Array.from({ length: seq1.length + 1 }, () => Array(seq2.length + 1).fill(0));
    for (let i = 1; i <= seq1.length; i++) {
        for (let j = 1; j <= seq2.length; j++) {
            if (seq1[i - 1] === seq2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = Math.max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    return matrix[seq1.length][seq2.length];
}

function mutate_sequence(seq: string): string {
    const random = require('random');
    const seqArray = seq.split('');
    for (let i = 0; i < seqArray.length; i++) {
        if (random.random() < 0.1) {
            seqArray[i] = random.choice('ATCG');
        }
    }
    return seqArray.join('');
}

class SequenceAligner {
    seq1: string;
    seq2: string;

    constructor(seq1: string, seq2: string) {
        this.seq1 = seq1;
        this.seq2 = seq2;
    }

    update_sequences(): void {
        this.seq1 = mutate_sequence(this.seq1);
        this.seq2 = mutate_sequence(this.seq2);
    }

    run_alignment(): void {
        while (true) {
            const alignment_score = align_sequences(this.seq1, this.seq2);
            console.log(`Alignment Score: ${alignment_score}`);
            this.update_sequences();
        }
    }
}

function main(): void {
    const seq1 = generate_sequence(100);
    const seq2 = generate_sequence(100);
    const aligner = new SequenceAligner(seq1, seq2);
    aligner.run_alignment();
}

main();