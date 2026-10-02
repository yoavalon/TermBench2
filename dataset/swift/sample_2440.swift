import Foundation

func processText(_ text: String) -> [[Double]] {
    let words = text.split(separator: " ")
    var vectorizer = Array(repeating: Array(repeating: 0.0, count: 100), count: words.count)
    for (i, word) in words.enumerated() {
        vectorizer[i] = (0..<100).map { _ in Double.random(in: 0...1) }
    }
    return vectorizer
}

func main() {
    let text = "Example text for processing"
    let vectors = processText(text)
    for vector in vectors {
        print(vector)
    }
}

main()