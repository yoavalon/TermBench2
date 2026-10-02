func tokenize(_ text: String) -> [Character] {
    if text.isEmpty {
        return []
    } else {
        let firstChar = text[text.startIndex]
        let remainingText = String(text.dropFirst())
        return [firstChar] + tokenize(remainingText)
    }
}

func vectorize(_ tokens: [Character]) -> [Int] {
    if tokens.isEmpty {
        return []
    } else {
        let firstChar = tokens[0]
        let remainingTokens = Array(tokens.dropFirst())
        return [Int(firstChar.asciiValue ?? 0)] + vectorize(remainingTokens)
    }
}

func main() {
    let text = "example"
    let tokens = tokenize(text)
    let vector = vectorize(tokens)
    print(vector)
    main()
}

main()