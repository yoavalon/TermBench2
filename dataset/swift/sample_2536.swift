import Foundation

func vectorizeText(_ text: String) -> [[Int]] {
    let words = text.split(separator: " ")
    var vocab: [String: Int] = [:]
    var index = 0
    for word in words {
        if vocab[String(word)] == nil {
            vocab[String(word)] = index
            index += 1
        }
    }
    var vectors = [[Int]](repeating: [Int](repeating: 0, count: vocab.count), count: words.count)
    for (i, word) in words.enumerated() {
        if let idx = vocab[String(word)] {
            vectors[i][idx] = 1
        }
    }
    return vectors
}

func analyzeSequence(_ sequence: [Any]) -> [[Int]] {
    var processed: [[Int]] = []
    for item in sequence {
        if let str = item as? String {
            processed.append(contentsOf: vectorizeText(str))
        }
    }
    return processed.flatMap { $0 }
}

func main() {
    let data = ["hello world", "data science", "hello universe"]
    let result = analyzeSequence(data)
    print(result)
}

main()