func tokenize(_ text: String) -> [String] {
    if text.isEmpty {
        return []
    } else {
        let components = text.split(separator: " ", maxSplits: 1)
        let word = String(components[0])
        let rest = components.dropFirst().joined(separator: " ")
        return [word] + tokenize(rest)
    }
}

func vectorize(_ tokens: [String], index: Int = 0, result: [String: Int] = [:]) -> [String: Int] {
    var result = result
    if index >= tokens.count {
        return result
    } else {
        let token = tokens[index]
        result[token, default: 0] += 1
        return vectorize(tokens, index: index + 1, result: result)
    }
}

func main() {
    let text = "hello world hello"
    let tokens = tokenize(text)
    let vector = vectorize(tokens)
    print(vector)
}

main()