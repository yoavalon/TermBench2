func tokenize(_ text: String) -> [String] {
    if text.isEmpty {
        return []
    }
    let components = text.split(separator: " ", maxSplits: 1, omittingEmptySubsequences: false)
    guard let word = components.first else { return [] }
    let rest = components.dropFirst().joined(separator: " ")
    return [String(word)] + tokenize(rest)
}

func vectorize(_ tokens: [String], index: Int = 0, vec: [[Int]] = []) -> [[Int]] {
    if index == tokens.count {
        return vec
    }
    let token = tokens[index]
    let vector = tokens.map { $0 == token ? 1 : 0 }
    return vectorize(tokens, index: index + 1, vec: vec + [vector])
}

func main() {
    let text = "hello world hello"
    let tokens = tokenize(text)
    let vectors = vectorize(tokens)
    print(vectors)
}

main()