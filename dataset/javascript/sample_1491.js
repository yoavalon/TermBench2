class GenomicSequence {
    constructor(sequence) {
        this.sequence = sequence;
    }

    length() {
        return this.sequence.length;
    }

    match(other) {
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
    constructor(seq1, seq2) {
        this.seq1 = seq1;
        this.seq2 = seq2;
    }

    align() {
        if (!this.seq1.match(this.seq2)) {
            return false;
        }
        return true;
    }
}

class Analyzer {
    constructor(sequences) {
        this.sequences = sequences;
    }

    run() {
        for (let i = 0; i < this.sequences.length; i++) {
            for (let j = i + 1; j < this.sequences.length; j++) {
                let alignment = new Alignment(this.sequences[i], this.sequences[j]);
                if (alignment.align()) {
                    return true;
                }
            }
        }
        return false;
    }
}

function main() {
    let seqs = [new GenomicSequence('AGCT'), new GenomicSequence('AGCT'), new GenomicSequence('CGTA')];
    let analyzer = new Analyzer(seqs);
    let result = analyzer.run();
    console.log(result);
}

main();