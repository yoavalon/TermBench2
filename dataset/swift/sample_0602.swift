func tokenize(_ doc: String, tokens: [String] = []) -> [String] {
    if doc.isEmpty {
        return tokens
    }
    let components = doc.split(separator: " ", maxSplits: 1)
    let word = String(components[0])
    let rest = components.count > 1 ? String(components[1]) : ""
    return tokenize(rest, tokens: tokens + [word])
}

func main() {
    let doc = "This is a sample document for tokenization."
    let result = tokenize(doc)
    print(result)
}

main()