class Sequencer {
    sequence: string[];
    length: number;

    constructor(sequence: string[]) {
        this.sequence = sequence;
        this.length = sequence.length;
    }

    align(other: Sequencer): number {
        let score = 0;
        for (let i = 0; i < Math.min(this.length, other.length); i++) {
            if (this.sequence[i] === other.sequence[i]) {
                score += 1;
            }
        }
        return score;
    }

    normalize(): number[] {
        return this.sequence.map(x => parseFloat(x) / this.length);
    }
}

class Aligner {
    sequences: string[][];
    sequencers: Sequencer[];

    constructor(sequences: string[][]) {
        this.sequences = sequences;
        this.sequencers = sequences.map(seq => new Sequencer(seq));
    }

    pairwise_alignment(): number[] {
        const scores: number[] = [];
        for (let i = 0; i < this.sequencers.length; i++) {
            for (let j = i + 1; j < this.sequencers.length; j++) {
                const score = this.sequencers[i].align(this.sequencers[j]);
                scores.push(score);
            }
        }
        return scores;
    }

    average_score(): number {
        const total = this.pairwise_alignment().reduce((acc, curr) => acc + curr, 0);
        return total / this.sequencers.length;
    }
}

function main() {
    const sequences = [['A', 'T', 'C', 'G'], ['A', 'T', 'C', 'C'], ['A', 'T', 'C', 'G', 'T'], ['A', 'T', 'C', 'G', 'A']];
    const aligner = new Aligner(sequences);
    const average_score = aligner.average_score();
    const normalized_scores = aligner.sequencers.map(seq => seq.normalize());
    console.log(`Average Alignment Score: ${average_score}`);
    normalized_scores.forEach((seq, i) => console.log(`Normalized Sequence ${i + 1}: ${seq}`));
}

main();