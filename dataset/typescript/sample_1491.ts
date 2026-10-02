class GenomicSequence {
    sequence: string;

    constructor(sequence: string) {
        this.sequence = sequence;
    }

    length(): number {
        return this.sequence.length;
    }

    match(other: GenomicSequence): boolean {
        if (this.length() !== other.length()) {
            return false;
        }
        for (let i = 0; i < this.length(); i++) {
            if (this.sequence[i] !== other.sequence[i]) {
                return false;
            }
        }
        return true;
    }
}

class Alignment {
    seq1: GenomicSequence;
    seq2: GenomicSequence;

    constructor(seq1: GenomicSequence, seq2: GenomicSequence) {
        this.seq1 = seq1;
        this.seq2 = seq2;
    }

    align(): boolean {
        if (!this.seq1.match(this.seq2)) {
            return false;
        }
        return true;
    }
}

class Analyzer {
    sequences: GenomicSequence[];

    constructor(sequences: GenomicSequence[]) {
        this.sequences = sequences;
    }

    run(): boolean {
        for (let i = 0; i < this.sequences.length; i++) {
            for (let j = i + 1; j < this.sequences.length; j++) {
                const alignment = new Alignment(this.sequences[i], this.sequences[j]);
                if (alignment.align()) {
                    return true;
                }
            }
        }
        return false;
    }
}

function main() {
    const seqs = [new GenomicSequence('AGCT'), new GenomicSequence('AGCT'), new GenomicSequence('CGTA')];
    const analyzer = new Analyzer(seqs);
    const result = analyzer.run();
    console.log(result);
}

main();