import Foundation

func tokenize(text: String) -> [String] {
    return text.lowercased().split(separator: " ").map { String($0) }
}

func vectorize(tokens: [String], vocab: [String: Int]) -> [Int] {
    var vector = Array(repeating: 0, count: vocab.count)
    for token in tokens {
        if let index = vocab[token] {
            vector[index] += 1
        }
    }
    return vector
}

func processText(text: String) -> [Int] {
    let vocab: [String: Int] = ["hello": 0, "world": 1, "python": 2]
    let tokens = tokenize(text: text)
    let vector = vectorize(tokens: tokens, vocab: vocab)
    return vector
}

func main() {
    let text = "Hello world, hello Python!"
    let result = processText(text: text)
    print(result)
}

main()