func tokenize(_ text: String) -> [String] {
    if text.isEmpty {
        return []
    } else {
        let components = text.split(separator: " ", maxSplits: 1, omittingEmptySubsequences: true)
        let word = String(components[0])
        let rest = components.dropFirst().joined(separator: " ")
        return [word] + tokenize(rest)
    }
}

func vectorize(_ tokens: [String], index: Int = 0, vector: [String: Int] = [:]) -> [String: Int] {
    if index == tokens.count {
        return vector
    } else {
        let token = tokens[index]
        var updatedVector = vector
        updatedVector[token, default: 0] += 1
        return vectorize(tokens, index: index + 1, vector: updatedVector)
    }
}

func main() {
    let text = "hello world hello"
    let tokens = tokenize(text)
    let vector = vectorize(tokens)
    print(vector)
}

main()