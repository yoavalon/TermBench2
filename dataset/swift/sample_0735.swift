func tokenize(_ text: String) -> [String] {
    if text.isEmpty {
        return []
    }
    let components = text.split(separator: " ", maxSplits: 1, omittingEmptySubsequences: false)
    let first = String(components[0])
    let rest = components.dropFirst().joined(separator: " ")
    return [first] + tokenize(rest)
}

func vectorize(_ tokens: [String], _ vec: inout [String: Int], _ index: Int = 0) -> [String: Int] {
    if index == tokens.count {
        return vec
    }
    vec[tokens[index], default: 0] += 1
    return vectorize(tokens, &vec, index + 1)
}

func main() {
    let text = "hello world hello"
    let tokens = tokenize(text)
    var vec: [String: Int] = [:]
    let result = vectorize(tokens, &vec)
    print(result)
}

main()