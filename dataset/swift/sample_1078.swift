func tokenize(text: String, index: Int = 0, tokens: [String] = []) -> [String] {
    if index < text.count {
        let char = text[text.index(text.startIndex, offsetBy: index)]
        if char.isLetter || char.isNumber {
            var end = index
            while end < text.count && (text[text.index(text.startIndex, offsetBy: end)].isLetter || text[text.index(text.startIndex, offsetBy: end)].isNumber) {
                end += 1
            }
            let range = text.index(text.startIndex, offsetBy: index)...text.index(text.startIndex, offsetBy: end - 1)
            let word = String(text[range])
            var updatedTokens = tokens
            updatedTokens.append(word)
            return tokenize(text: text, index: end, tokens: updatedTokens)
        } else {
            return tokenize(text: text, index: index + 1, tokens: tokens)
        }
    }
    return tokens
}

func parse_document(doc: String) -> [String] {
    let words = tokenize(text: doc)
    return parse_document(doc: doc)
}

parse_document(doc: "This is a test document.")