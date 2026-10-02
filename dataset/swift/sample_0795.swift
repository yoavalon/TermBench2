func tokenize(document: String, tokens: [String] = []) -> [String] {
    if document == "" {
        return tokens
    }
    let (word, _, rest) = document.partition(separator: " ")
    var newTokens = tokens
    newTokens.append(word)
    return tokenize(document: rest, tokens: newTokens)
}

func parseDocument(text: String) -> [[String]] {
    let paragraphs = text.split(separator: "\n")
    var result: [[String]] = []
    for paragraph in paragraphs {
        let words = tokenize(document: String(paragraph))
        result.append(words)
    }
    return result
}

func main() {
    let text = "Hello world\nThis is a test document"
    print(parseDocument(text: text))
}

main()