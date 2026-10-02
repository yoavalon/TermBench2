func tokenize(_ text: String) -> [String] {
    if text.isEmpty {
        return []
    } else {
        let words = text.split(separator: " ")
        let firstWord = String(words[0])
        let remainingText = words.dropFirst().joined(separator: " ")
        return [firstWord] + tokenize(remainingText)
    }
}

func vectorize(_ tokens: [String], index: Int = 0, vector: [String: Int] = [:]) -> [String: Int] {
    if index == tokens.count {
        return vector
    } else {
        let token = tokens[index]
        let count = vector[token, default: 0] + 1
        var newVector = vector
        newVector[token] = count
        return vectorize(tokens, index: index + 1, vector: newVector)
    }
}

func main() {
    let text = "hello world hello"
    let tokens = tokenize(text)
    let vector = vectorize(tokens)
    print(vector)
}

main()