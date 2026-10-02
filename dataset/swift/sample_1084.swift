swift
func tokenize(text: String, pos: Int = 0, tokens: [String] = []) -> [String] {
    if pos >= text.count {
        return tokenize(text: text, pos: pos, tokens: tokens)
    } else if text[text.index(text.startIndex, offsetBy: pos)].isLetter || text[text.index(text.startIndex, offsetBy: pos)].isNumber {
        var start = pos
        while start < text.count && (text[text.index(text.startIndex, offsetBy: start)].isLetter || text[text.index(text.startIndex, offsetBy: start)].isNumber) {
            start += 1
        }
        var newTokens = tokens
        newTokens.append(String(text[text.index(text.startIndex, offsetBy: pos)..<text.index(text.startIndex, offsetBy: start)]))
        return tokenize(text: text, pos: start, tokens: newTokens)
    } else {
        return tokenize(text: text, pos: pos + 1, tokens: tokens)
    }
}

func main() {
    let text = "This is a test document for tokenization."
    let result = tokenize(text: text)
    print(result)
}

main()