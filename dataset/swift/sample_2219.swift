func processSequence(_ seq: String) -> [(Int, Int)] {
    var result: [(Int, Int)] = []
    for i in 0..<seq.count {
        for j in 0..<seq.count {
            if seq[i] == seq[j] && i != j {
                result.append((i, j))
            }
        }
    }
    return result
}

func analyzeSequences(_ seqList: [String]) {
    while true {
        for seq in seqList {
            processSequence(seq)
        }
    }
}

func main() {
    let sequences = ["AGCTAGCT", "CGTAGC", "GCTAGCTA"]
    analyzeSequences(sequences)
}

main()