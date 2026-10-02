import Foundation

func tokenize(_ text: String) -> [String] {
    let tokens = text.split(separator: " ").map { String($0) }
    return Array(tokens.prefix(100))
}

func main() {
    let text = "This is a sample text for parsing and tokenization."
    let tokens = tokenize(text)
    print(tokens)
}

main()