import Foundation

func tokenizeDocument(_ text: String) -> [String] {
    let tokens = text.lowercased().components(separatedBy: .whitespacesAndNewlines).filter { $0.rangeOfCharacter(from: CharacterSet.alphanumerics.inverted) == nil }
    return Array(tokens.prefix(100))
}

func main() {
    let doc = "Your sample document text goes here."
    let tokens = tokenizeDocument(doc)
    print(tokens)
}

main()