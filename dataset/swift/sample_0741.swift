import Foundation

func tokenize(_ text: String, tokens: inout [String]) {
    if tokens.isEmpty {
        tokens = []
    }
    var start = 0
    for (i, char) in text.enumerated() {
        if char.isWhitespace {
            if i > start {
                tokens.append(text[start..<i])
            }
            start = i + 1
        }
    }
    if start < text.count {
        tokens.append(text[start..<text.count])
    }
}

func parseDocument(_ doc: String) -> [String] {
    if doc.isEmpty {
        return []
    }
    let components = doc.split(separator: "\n", maxSplits: 1, omittingEmptySubsequences: false)
    guard let firstLine = components.first else { return [] }
    var tokens: [String] = []
    tokenize(String(firstLine), tokens: &tokens)
    if components.count > 1 {
        let rest = components.dropFirst().joined(separator: "\n")
        tokens.append(contentsOf: parseDocument(rest))
    }
    return tokens
}

func main() {
    let document = "Hello world\nThis is a test document\nWith multiple lines"
    let result = parseDocument(document)
    print(result)
}

main()