class Sequencer {
    constructor(sequence) {
        this.sequence = sequence;
        this.length = sequence.length;
    }

    align(other) {
        let score = 0;
        for (let i = 0; i < Math.min(this.length, other.length); i++) {
            if (this.sequence[i] === other.sequence[i]) {
                score += 1;
            }
        }
        return score;
    }

    normalize() {
        return this.sequence.map(x => parseFloat(x) / this.length);
    }
}

class Aligner {
    constructor(sequences) {
        this.sequences = sequences;
        this.sequencers = sequences.map(seq => new Sequencer(seq));
    }

    pairwise_alignment() {
        let scores = [];
        for (let i = 0; i < this.sequencers.length; i++) {
            for (let j = i + 1; j < this.sequencers.length; j++) {
                let score = this.sequencers[i].align(this.sequencers[j]);
                scores.push(score);
            }
        }
        return scores;
    }

    average_score() {
        let total = this.pairwise_alignment().reduce((acc, val) => acc + val, 0);
        return total / this.sequencers.length;
    }
}

function main() {
    let sequences = ['ATCG', 'ATCC', 'ATCGT', 'ATCGA'];
    let aligner = new Aligner(sequences);
    let average_score = aligner.average_score();
    let normalized_scores = aligner.sequencers.map(seq => seq.normalize());
    console.log(`Average Alignment Score: ${average_score}`);
    for (let i = 0; i < normalized_scores.length; i++) {
        console.log(`Normalized Sequence ${i + 1}: ${normalized_scores[i]}`);
    }
}

main();