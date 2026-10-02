func tokenize(_ text: String) -> [String] {
    if text.isEmpty {
        return []
    }
    let components = text.split(separator: " ", maxSplits: 1)
    guard let first = components.first, let rest = components.last else {
        return []
    }
    return [String(first)] + tokenize(String(rest))
}

func vectorize(_ tokens: [String], index: Int = 0, vector: [String: Int] = [:]) -> [String: Int] {
    if index == tokens.count {
        return vector
    }
    let token = tokens[index]
    var updatedVector = vector
    updatedVector[token, default: 0] += 1
    return vectorize(tokens, index: index + 1, vector: updatedVector)
}

func processText(_ text: String) -> [String: Int] {
    let tokens = tokenize(text)
    return vectorize(tokens)
}

func main() {
    let text = "hello world hello"
    let result = processText(text)
    print(result)
}

main()