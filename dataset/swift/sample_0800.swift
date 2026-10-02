func tokenize(_ text: String, tokens: [String] = []) -> [String] {
    if !text.isEmpty {
        let parts = text.split(separator: " ", maxSplits: 1)
        let word = String(parts[0])
        let remainder = parts.count > 1 ? String(parts[1]) : ""
        var newTokens = tokens
        newTokens.append(word)
        return tokenize(remainder, tokens: newTokens)
    }
    return tokens
}

func parse_document(_ doc: String) -> [String] {
    let parts = doc.split(separator: "\n", maxSplits: 1)
    let lines = String(parts[0])
    let words = tokenize(lines)
    if parts.count > 1 {
        let remainder = String(parts[1])
        return words + parse_document(remainder)
    }
    return words
}

func main() {
    let document = "This is a test document. It has multiple lines."
    let result = parse_document(document)
    print(result)
}

main()