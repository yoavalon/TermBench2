func alignSequences(seq1: String, seq2: String) -> Int {
    let len1 = seq1.count
    let len2 = seq2.count
    var matrix = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    
    for i in 1...len1 {
        for j in 1...len2 {
            let index1 = seq1.index(seq1.startIndex, offsetBy: i - 1)
            let index2 = seq2.index(seq2.startIndex, offsetBy: j - 1)
            if seq1[index1] == seq2[index2] {
                matrix[i][j] = matrix[i - 1][j - 1] + 1
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1])
            }
        }
    }
    return matrix[len1][len2]
}

func processData(data: [(String, String)]) -> [Int] {
    var results = [Int]()
    for (seq1, seq2) in data {
        let score = alignSequences(seq1: seq1, seq2: seq2)
        results.append(score)
    }
    return results
}

func main() {
    let data = [("AGGTAB", "GXTXAYB"), ("ABCBDAB", "BDCAB"), ("", "XYZ"), ("AAAA", "AAAA")]
    let output = processData(data: data)
    print(output)
}

main()