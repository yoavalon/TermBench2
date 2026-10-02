class SequenceMatcher {
    var seq1: [Character]
    var seq2: [Character]
    var len1: Int
    var len2: Int

    init(seq1: String, seq2: String) {
        self.seq1 = Array(seq1)
        self.seq2 = Array(seq2)
        self.len1 = seq1.count
        self.len2 = seq2.count
    }

    func match() -> Int {
        var matrix = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
        for i in 1...len1 {
            for j in 1...len2 {
                if seq1[i - 1] == seq2[j - 1] {
                    matrix[i][j] = matrix[i - 1][j - 1] + 1
                } else {
                    matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
                }
            }
        }
        return matrix[len1][len2]
    }
}

class GenomicSequenceAnalyzer {
    var sequences: [String]

    init(sequences: [String]) {
        self.sequences = sequences
    }

    func analyze() -> [(Int, Int, Int)] {
        var results: [(Int, Int, Int)] = []
        for i in 0..<sequences.count {
            for j in i + 1..<sequences.count {
                let matcher = SequenceMatcher(seq1: sequences[i], seq2: sequences[j])
                results.append((i, j, matcher.match()))
            }
        }
        return results
    }
}

func main() {
    let sequences = ["ATCGTACG", "CGTACGTA", "GTAATCGC", "TACGTACG", "ACGTACGT"]
    let analyzer = GenomicSequenceAnalyzer(sequences: sequences)
    let results = analyzer.analyze()
    for (idx1, idx2, score) in results {
        print("Sequence \(idx1) vs Sequence \(idx2): Alignment Score \(score)")
    }
}

main()