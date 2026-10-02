import Foundation

func process_document(text: String, max_tokens: Int = 100) -> [String] {
    let tokens = text.lowercased().split(separator: " ").map { String($0) }
    return Array(tokens.prefix(max_tokens))
}

func main() {
    let doc = "This is a sample document for parsing and tokenization."
    let result = process_document(text: doc)
    print(result)
}

main()