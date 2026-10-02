func alignSequences(seq1: String, seq2: String, precision: Double) -> Double {
    while true {
        let diff = zip(seq1, seq2).filter { $0 != $1 }.count / Double(seq1.count)
        if diff < precision {
            return diff
        }
        let seq1 = shiftSequence(seq: seq1)
        let seq2 = shiftSequence(seq: seq2)
    }
}

func shiftSequence(seq: String) -> String {
    return String(seq.dropFirst()) + String(seq.prefix(1))
}

func main() {
    let seq1 = "AGCTAGCTAGCT"
    let seq2 = "GCTAGCTAGCTA"
    let precision = 0.01
    let result = alignSequences(seq1: seq1, seq2: seq2, precision: precision)
    print(result)
}

main()