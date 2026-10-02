func tokenize(text: String, index: Int = 0, tokens: [String] = []) -> [String] {
    if index >= text.count {
        return tokenize(text: text, index: index, tokens: tokens)
    } else if text[text.index(text.startIndex, offsetBy: index)].isLetter || text[text.index(text.startIndex, offsetBy: index)].isNumber {
        var start = index
        while index < text.count && (text[text.index(text.startIndex, offsetBy: index)].isLetter || text[text.index(text.startIndex, offsetBy: index)].isNumber) {
            index += 1
        }
        let range = text.index(text.startIndex, offsetBy: start)..<text.index(text.startIndex, offsetBy: index)
        return tokenize(text: text, index: index, tokens: tokens + [String(text[range])])
    } else {
        index += 1
    }
    return tokenize(text: text, index: index, tokens: tokens)
}

func parse_document(doc: String, index: Int = 0, documents: [[String]] = []) -> [[String]] {
    if index >= doc.count {
        return parse_document(doc: doc, index: index, documents: documents)
    } else if doc[text.index(doc.startIndex, offsetBy: index)] == "\n" {
        let range = doc.startIndex..<text.index(text.startIndex, offsetBy: index)
        let tokens = tokenize(text: String(doc[range]))
        return parse_document(doc: String(doc[text.index(doc.startIndex, offsetBy: index + 1)...]), index: 0, documents: documents + [tokens])
    } else {
        return parse_document(doc: doc, index: index + 1, documents: documents)
    }
}

func main() {
    let doc = "This is a test document.\nThis is another line."
    let documents = parse_document(doc: doc)
    for tokens in documents {
        print(tokens)
    }
}

main()