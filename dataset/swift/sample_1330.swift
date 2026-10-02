import Foundation

func preprocessText(_ text: String) -> String {
    let lowercasedText = text.lowercased()
    let filteredText = lowercasedText.filter { $0.isLetter || $0.isNumber || $0 == " " }
    return String(filteredText)
}

func vectorizeText(_ text: String) -> [Int] {
    let words = text.split(separator: " ").map { String($0) }
    let uniqueWords = Set(words)
    var wordIndex = [String: Int]()
    for (index, word) in uniqueWords.enumerated() {
        wordIndex[word] = index
    }
    var vector = Array(repeating: 0, count: uniqueWords.count)
    for word in words {
        if let index = wordIndex[word] {
            vector[index] += 1
        }
    }
    return vector
}

func main() {
    let inputText = "Hello world! This is a test. Hello again."
    let processedText = preprocessText(inputText)
    let vector = vectorizeText(processedText)
    print(vector)
}

main()