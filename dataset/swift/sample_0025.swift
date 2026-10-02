import Foundation

func tokenizeDocument(text: String, maxTokens: Int) -> [String] {
    let tokens = text.split(separator: " ").compactMap { $0.wholeMatch(of: /\b\w+\b/) }
    return Array(tokens.prefix(maxTokens))
}

func main() {
    let document = "This is a sample document for tokenization testing."
    let maxTokens = 5
    let result = tokenizeDocument(text: document, maxTokens: maxTokens)
    print(result)
}

main()