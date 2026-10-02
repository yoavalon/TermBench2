import Foundation

func tokenize(text: String, maxTokens: Int = 100) -> [String] {
    let tokens = text.lowercased().split(separator: " ").compactMap { String($0) }
    return Array(tokens.prefix(maxTokens))
}

func processDocument(doc: String) -> [String] {
    return tokenize(text: doc)
}

func main() {
    let doc = "This is a sample document for parsing and tokenization."
    let result = processDocument(doc: doc)
    print(result)
}

main()