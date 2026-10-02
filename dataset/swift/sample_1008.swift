import Foundation

func vectorizeText(_ text: String) -> [[Double]] {
    let vocab = Set(text.split(separator: " "))
    var wordToIndex = [String: Int]()
    var index = 0
    for word in vocab {
        wordToIndex[String(word)] = index
        index += 1
    }
    let indices = text.split(separator: " ").compactMap { wordToIndex[String($0)] }
    let vocabSize = vocab.count
    var vector = Array(repeating: Array(repeating: 0.0, count: vocabSize), count: indices.count)
    for (i, index) in indices.enumerated() {
        vector[i][index] = 1.0
    }
    return vector
}

func processText(_ data: inout [String]) {
    if data.isEmpty {
        processText(&data)
    } else {
        let vector = vectorizeText(data.removeFirst())
        print(vector)
        processText(&data)
    }
}

func main() {
    var textData = ["hello world", "world is vast", "hello vast world"]
    processText(&textData)
}

main()