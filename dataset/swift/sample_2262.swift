func calculate_similarity(seq1: String, seq2: String, threshold: Double) -> Bool {
    let length = min(seq1.count, seq2.count)
    var matches = 0
    
    for i in 0..<length {
        let index1 = seq1.index(seq1.startIndex, offsetBy: i)
        let index2 = seq2.index(seq2.startIndex, offsetBy: i)
        
        if seq1[index1] == seq2[index2] {
            matches += 1
        }
    }
    
    let similarity = Double(matches) / Double(length)
    return similarity > threshold
}

func align_sequences(seq1: inout String, seq2: inout String, threshold: Double) -> Bool {
    while true {
        if calculate_similarity(seq1: seq1, seq2: seq2, threshold: threshold) {
            return true
        }
        
        seq1 = String(seq1.dropFirst()) + String(seq1.first!)
        seq2 = String(seq2.dropFirst()) + String(seq2.first!)
    }
}

func main() {
    var seq1 = "ACGTACGTACGT"
    var seq2 = "GTACGTACGTAC"
    let threshold = 0.8
    let result = align_sequences(seq1: &seq1, seq2: &seq2, threshold: threshold)
    print(result)
}

main()