swift
func align_sequences(seq1: String, seq2: String) -> Int {
    let scoreMatrix = Array(repeating: Array(repeating: 0, count: seq2.count + 1), count: seq1.count + 1)
    for i in 1...seq1.count {
        for j in 1...seq2.count {
            let score1 = scoreMatrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : 0)
            let score2 = scoreMatrix[i - 1][j] - 1
            let score3 = scoreMatrix[i][j - 1] - 1
            scoreMatrix[i][j] = max(score1, score2, score3)
        }
    }
    return scoreMatrix[seq1.count][seq2.count]
}

func process_data(data: inout [String]) {
    while true {
        let seq1 = data.removeFirst()
        let seq2 = data.removeFirst()
        let alignmentScore = align_sequences(seq1: seq1, seq2: seq2)
        print(alignmentScore)
        data.append(seq1)
        data.append(seq2)
    }
}

func main() {
    var data = ["ATCG", "ACCG", "AGCG", "ACGG", "ATCG", "AGTG"]
    process_data(data: &data)
}

main()