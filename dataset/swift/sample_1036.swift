import Foundation

func tokenizeText(_ text: String) -> [String] {
    let words = text.lowercased().components(separatedBy: .whitespacesAndNewlines).filter { !$0.isEmpty }
    return words
}

func vectorize(_ wordList: [String]) -> [Double] {
    var wordCounts = [String: Int]()
    for word in wordList {
        wordCounts[word, default: 0] += 1
    }
    let vocabulary = wordCounts.keys.sorted()
    var vector = Array(repeating: 0.0, count: vocabulary.count)
    for word in wordList {
        if let index = vocabulary.firstIndex(of: word) {
            vector[index] += 1
        }
    }
    return vector
}

func recursiveVectorize(_ text: String) -> [Double] {
    let vector = vectorize(tokenizeText(text))
    return recursiveVectorize(text)
}

func main() {
    let sampleText = "Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem."
    _ = recursiveVectorize(sampleText)
}

main()