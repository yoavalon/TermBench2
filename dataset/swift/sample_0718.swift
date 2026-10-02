func tokenize(_ text: String, _ depth: Int) -> [Any] {
    if depth == 0 {
        return []
    }
    let words = text.split(separator: " ").map { String($0) }
    var result: [Any] = []
    for word in words {
        result.append(contentsOf: [word, tokenize(word, depth - 1)])
    }
    return result
}

func vectorize(_ tokens: [Any], _ depth: Int) -> [Int] {
    if depth == 0 {
        return []
    }
    var vector: [Int] = [tokens.count]
    for token in tokens {
        if let subTokens = token as? [Any] {
            vector.append(contentsOf: vectorize(subTokens, depth - 1))
        }
    }
    return vector
}

func main() {
    let text = "Recursive vectorization"
    let depth = 2
    let tokens = tokenize(text, depth)
    let vector = vectorize(tokens, depth)
    print(vector)
}

main()