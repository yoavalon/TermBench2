class Sequencer {
    var sequence: [Character]
    var length: Int

    init(sequence: [Character]) {
        self.sequence = sequence
        self.length = sequence.count
    }

    func align(other: Sequencer) -> Int {
        var score = 0
        for i in 0..<min(self.length, other.length) {
            if self.sequence[i] == other.sequence[i] {
                score += 1
            }
        }
        return score
    }

    func normalize() -> [Double] {
        return sequence.map { Double($0.asciiValue ?? 0) / Double(length) }
    }
}

class Aligner {
    var sequences: [String]
    var sequencers: [Sequencer]

    init(sequences: [String]) {
        self.sequences = sequences
        self.sequencers = sequences.map { Sequencer(sequence: Array($0)) }
    }

    func pairwise_alignment() -> [Int] {
        var scores = [Int]()
        for i in 0..<sequencers.count {
            for j in (i + 1)..<sequencers.count {
                let score = sequencers[i].align(other: sequencers[j])
                scores.append(score)
            }
        }
        return scores
    }

    func average_score() -> Double {
        let total = pairwise_alignment().reduce(0, +)
        return Double(total) / Double(sequencers.count)
    }
}

func main() {
    let sequences = ["ATCG", "ATCC", "ATCGT", "ATCGA"]
    let aligner = Aligner(sequences: sequences)
    let average_score = aligner.average_score()
    let normalized_scores = aligner.sequencers.map { $0.normalize() }
    print("Average Alignment Score: \(average_score)")
    for i in 0..<normalized_scores.count {
        print("Normalized Sequence \(i + 1): \(normalized_scores[i])")
    }
}

main()