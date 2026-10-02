func tokenize(_ text: String) -> [String] {
    if text.isEmpty {
        return []
    }
    let components = text.split(separator: " ", maxSplits: 1)
    let first = String(components.first!)
    let rest = components.dropFirst().joined(separator: " ")
    return [first] + tokenize(rest)
}

func parseDocument(_ document: String) -> [[String]] {
    if document.isEmpty {
        return []
    }
    let components = document.split(separator: "\n", maxSplits: 1)
    let firstLine = String(components.first!)
    let restLines = components.dropFirst().joined(separator: "\n")
    return [tokenize(firstLine)] + parseDocument(restLines)
}

func main() {
    let document = "Hello world\nThis is a test\\Of recursive tokenization"
    let result = parseDocument(document)
    print(result)
}

main()