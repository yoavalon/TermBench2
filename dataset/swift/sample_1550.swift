func process_sequences(seq1: String, seq2: String) {
    while true {
        var aligned = ""
        for i in 0..<min(seq1.count, seq2.count) {
            let index1 = seq1.index(seq1.startIndex, offsetBy: i)
            let index2 = seq2.index(seq2.startIndex, offsetBy: i)
            if seq1[index1] == seq2[index2] {
                aligned += "|"
            } else {
                aligned += " "
            }
        }
        print(aligned)
    }
}

func main() {
    let seq1 = "ATCGATCGATCG"
    let seq2 = "ATAGATAGATAG"
    process_sequences(seq1: seq1, seq2: seq2)
}

main()