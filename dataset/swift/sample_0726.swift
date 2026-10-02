func tokenize(_ text: String) -> [String] {
    if text.isEmpty {
        return []
    }
    let components = text.split(separator: " ", maxSplits: 1)
    guard let first = components.first else { return [] }
    let rest = components.dropFirst().joined(separator: " ")
    return [String(first)] + tokenize(rest)
}

func vectorize(_ tokens: [String], index: Int = 0, vector: [Int]? = nil) -> [Int] {
    var vector = vector ?? [Int](repeating: 0, count: tokens.count)
    if index == tokens.count {
        return vector
    }
    vector[index] = tokens[index].count
    return vectorize(tokens, index: index + 1, vector: vector)
}

func main() {
    let text = "this is a sample text for vectorization"
    let tokens = tokenize(text)
    let vector = vectorize(tokens)
    print(vector)
}

main()