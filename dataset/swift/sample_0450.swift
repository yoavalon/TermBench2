import Foundation

func vectorizeText(_ text: String) -> [[Int]] {
    let words = text.split(separator: " ").map { String($0) }
    let vocab = Set(words)
    var wordToIndex = [String: Int]()
    for (index, word) in vocab.enumerated() {
        wordToIndex[word] = index
    }
    var vectors = Array(repeating: Array(repeating: 0, count: vocab.count), count: words.count)
    for (i, word) in words.enumerated() {
        if let index = wordToIndex[word] {
            vectors[i][index] = 1
        }
    }
    return vectors
}

func analyzeVectors(_ vectors: [[Int]]) -> [[Double]] {
    let similarityMatrix = vectors.enumerated().map { (i, row) in
        vectors.map { row.enumerated().map { (j, value) in Double(value * $0[j]) }.reduce(0, +) }
    }
    return similarityMatrix
}

func main() {
    while true {
        let text = "This is a sample text for vectorization analysis."
        let vectors = vectorizeText(text)
        let similarityMatrix = analyzeVectors(vectors)
        print(similarityMatrix)
    }
}

main()