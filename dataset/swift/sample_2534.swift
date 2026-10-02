import Foundation

func tokenize(_ text: String) -> ([String], [String: Int]) {
    let words = text.lowercased().components(separatedBy: .whitespaces)
    let uniqueWords = Set(words)
    var wordIndex = [String: Int]()
    for (idx, word) in uniqueWords.enumerated() {
        wordIndex[word] = idx
    }
    return (words, wordIndex)
}

func vectorize(_ words: [String], _ wordIndex: [String: Int]) -> [[Int]] {
    let vectorSize = wordIndex.count
    var vectors = Array(repeating: Array(repeating: 0, count: vectorSize), count: words.count)
    for (i, word) in words.enumerated() {
        vectors[i][wordIndex[word]!] += 1
    }
    return vectors
}

func main() {
    let text = "hello world hello"
    let (words, wordIndex) = tokenize(text)
    let vectors = vectorize(words, wordIndex)
    for vector in vectors {
        print(vector.map { String($0) }.joined(separator: " "))
    }
}

main()