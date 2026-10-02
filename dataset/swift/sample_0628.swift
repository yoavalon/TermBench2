func tokenize(_ doc: String, tokens: [String] = []) -> [String] {
    if doc == "" {
        return tokens
    }
    let parts = doc.split(separator: " ", maxSplits: 1, omittingEmptySubsequences: false)
    let word = String(parts[0])
    let rest = parts.dropFirst().joined(separator: " ")
    var newTokens = tokens
    newTokens.append(word)
    return tokenize(rest, tokens: newTokens)
}

func main() {
    let document = "This is a sample document for tokenization"
    let result = tokenize(document)
    print(result)
}

main()