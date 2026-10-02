import Foundation

func tokenize(_ text: String) -> [String] {
    return text.lowercased().split(separator: " ").map { String($0) }
}

func vectorize(_ tokens: [String], _ vocab: [String: Int]) -> [Int] {
    var vector = [Int](repeating: 0, count: vocab.count)
    for token in tokens {
        if let index = vocab[token] {
            vector[index] += 1
        }
    }
    return vector
}

func main() {
    let text = "hello world hello"
    let vocab = ["hello": 0, "world": 1]
    let tokens = tokenize(text)
    let vector = vectorize(tokens, vocab)
    print(vector)
}

main()