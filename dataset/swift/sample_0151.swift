func initializeSequence(seq: String) -> [String: Any] {
    return ["sequence": seq, "position": 0]
}

func alignSequences(seq1: String, seq2: String) -> Int {
    var seq1Data = initializeSequence(seq: seq1)
    var seq2Data = initializeSequence(seq: seq2)
    while seq1Data["position"] as! Int < (seq1Data["sequence"] as! String).count && seq2Data["position"] as! Int < (seq2Data["sequence"] as! String).count {
        let seq1Char = (seq1Data["sequence"] as! String).index((seq1Data["sequence"] as! String).startIndex, offsetBy: seq1Data["position"] as! Int)
        let seq2Char = (seq2Data["sequence"] as! String).index((seq2Data["sequence"] as! String).startIndex, offsetBy: seq2Data["position"] as! Int)
        if (seq1Data["sequence"] as! String)[seq1Char] == (seq2Data["sequence"] as! String)[seq2Char] {
            seq1Data["position"] = (seq1Data["position"] as! Int) + 1
            seq2Data["position"] = (seq2Data["position"] as! Int) + 1
        } else {
            seq1Data["position"] = (seq1Data["position"] as! Int) + 1
        }
    }
    return seq1Data["position"] as! Int
}

func main() {
    let sequence1 = "AGCTAGCTAGCT"
    let sequence2 = "AGCTAGCTAGCT"
    let result = alignSequences(seq1: sequence1, seq2: sequence2)
    print(result)
}

main()