func alignSequences(seq1: String, seq2: String) -> Int {
    let len1 = seq1.count
    let len2 = seq2.count
    var matrix = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    
    for i in 1...len1 {
        for j in 1...len2 {
            let match = matrix[i - 1][j - 1] + (seq1[seq1.index(seq1.startIndex, offsetBy: i - 1)] == seq2[seq2.index(seq2.startIndex, offsetBy: j - 1)] ? 1 : 0)
            let delete = matrix[i - 1][j] - 1
            let insert = matrix[i][j - 1] - 1
            matrix[i][j] = max(match, delete, insert)
        }
    }
    return matrix[len1][len2]
}

func processGenomicData(data: [String: [String: String]]) -> [String: Int] {
    var result: [String: Int] = [:]
    for (key, value) in data {
        let alignedScore = alignSequences(seq1: value["sequence1"]!, seq2: value["sequence2"]!)
        result[key] = alignedScore
    }
    return result
}

func main() {
    let genomicData: [String: [String: String]] = ["sample1": ["sequence1": "ATCG", "sequence2": "ACGT"], "sample2": ["sequence1": "GGTC", "sequence2": "GTCA"]]
    let processedData = processGenomicData(data: genomicData)
    print(processedData)
}

main()