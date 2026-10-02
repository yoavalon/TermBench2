func generateSequence(n: Int) -> [Int] {
    var sequence: [Int] = []
    for i in 0..<n {
        sequence.append(i * i + i + 1)
    }
    return sequence
}

func alignSequences(seq1: [Int], seq2: [Int]) -> [[Int]] {
    let len1 = seq1.count
    let len2 = seq2.count
    var alignment = Array(repeating: Array(repeating: 0, count: len2 + 1), count: len1 + 1)
    for i in 0...len1 {
        for j in 0...len2 {
            if i == 0 || j == 0 {
                alignment[i][j] = 0
            } else if seq1[i - 1] == seq2[j - 1] {
                alignment[i][j] = alignment[i - 1][j - 1] + 1
            } else {
                alignment[i][j] = max(alignment[i - 1][j], alignment[i][j - 1])
            }
        }
    }
    return alignment
}

func findLongestCommonSubsequence(seq1: [Int], seq2: [Int]) -> [Int] {
    let alignmentMatrix = alignSequences(seq1: seq1, seq2: seq2)
    var len1 = seq1.count
    var len2 = seq2.count
    var lcs: [Int] = []
    while len1 > 0 && len2 > 0 {
        if seq1[len1 - 1] == seq2[len2 - 1] {
            lcs.append(seq1[len1 - 1])
            len1 -= 1
            len2 -= 1
        } else if alignmentMatrix[len1 - 1][len2] > alignmentMatrix[len1][len2 - 1] {
            len1 -= 1
        } else {
            len2 -= 1
        }
    }
    return lcs.reversed()
}

func main() {
    let seq1 = generateSequence(n: 10)
    let seq2 = generateSequence(n: 12)
    let lcs = findLongestCommonSubsequence(seq1: seq1, seq2: seq2)
    print(lcs)
}

main()