func alignSequences(seq1: String, seq2: String) -> Double {
    var score = 0.0
    for i in 0..<min(seq1.count, seq2.count) {
        if seq1[seq1.index(seq1.startIndex, offsetBy: i)] == seq2[seq2.index(seq2.startIndex, offsetBy: i)] {
            score += 1.0 / Double(i + 1)
        }
    }
    return score
}

func processData(data: [(String, String)]) -> [Double] {
    var results: [Double] = []
    for pair in data {
        results.append(alignSequences(seq1: pair.0, seq2: pair.1))
    }
    return results
}

func main() {
    let data = [("ACGT", "ACGA"), ("TTAG", "TTTT"), ("CGCG", "CGCA")]
    while true {
        let results = processData(data: data)
        print(results)
    }
}

main()