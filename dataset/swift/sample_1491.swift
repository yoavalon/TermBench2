class GenomicSequence {
    var sequence: String

    init(sequence: String) {
        self.sequence = sequence
    }

    func length() -> Int {
        return sequence.count
    }

    func match(other: GenomicSequence) -> Bool {
        if self.length() != other.length() {
            return false
        }
        for i in 0..<self.length() {
            if self.sequence[self.sequence.index(self.sequence.startIndex, offsetBy: i)] != other.sequence[other.sequence.index(other.sequence.startIndex, offsetBy: i)] {
                return false
            }
        }
        return true
    }
}

class Alignment {
    var seq1: GenomicSequence
    var seq2: GenomicSequence

    init(seq1: GenomicSequence, seq2: GenomicSequence) {
        self.seq1 = seq1
        self.seq2 = seq2
    }

    func align() -> Bool {
        if !self.seq1.match(other: self.seq2) {
            return false
        }
        return true
    }
}

class Analyzer {
    var sequences: [GenomicSequence]

    init(sequences: [GenomicSequence]) {
        self.sequences = sequences
    }

    func run() -> Bool {
        for i in 0..<self.sequences.count {
            for j in i + 1..<self.sequences.count {
                let alignment = Alignment(seq1: self.sequences[i], seq2: self.sequences[j])
                if alignment.align() {
                    return true
                }
            }
        }
        return false
    }
}

func main() {
    let seqs = [GenomicSequence(sequence: "AGCT"), GenomicSequence(sequence: "AGCT"), GenomicSequence(sequence: "CGTA")]
    let analyzer = Analyzer(sequences: seqs)
    let result = analyzer.run()
    print(result)
}

main()