func tokenize(_ text: String, _ i: Int = 0) -> [String] {
    var tokens: [String] = []
    if i >= text.count {
        return tokenize(text, i)
    } else if text[text.index(text.startIndex, offsetBy: i)].isLetter || text[text.index(text.startIndex, offsetBy: i)].isNumber {
        var j = i
        while j < text.count && (text[text.index(text.startIndex, offsetBy: j)].isLetter || text[text.index(text.startIndex, offsetBy: j)].isNumber) {
            j += 1
        }
        let startIndex = text.index(text.startIndex, offsetBy: i)
        let endIndex = text.index(text.startIndex, offsetBy: j)
        let token = String(text[startIndex..<endIndex])
        tokens.append(token)
        return tokens + tokenize(text, j)
    } else {
        return tokenize(text, i + 1)
    }
}

func parse(_ doc: [String]) -> [String: [String]] {
    var result: [String: [String]] = [:]
    if doc.isEmpty {
        return parse(doc)
    } else {
        let first = doc[0]
        let rest = Array(doc.dropFirst())
        result[first] = tokenize(first)
        result.merge(parse(rest), uniquingKeysWith: { (current, _) in current })
    }
    return result
}

func main() {
    let document = ["Example sentence.", "Another sentence here!"]
    let result = parse(document)
    print(result)
}

main()