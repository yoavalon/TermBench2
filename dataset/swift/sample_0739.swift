func tokenize(text: String, delimiters: [Character]) -> [String] {
    if text.isEmpty {
        return []
    } else if delimiters.contains(text.first!) {
        return tokenize(text: String(text.dropFirst()), delimiters: delimiters)
    } else if delimiters.contains(text.last!) {
        return tokenize(text: String(text.dropLast()), delimiters: delimiters)
    } else {
        if let firstSpaceIndex = text.firstIndex(of: " ") {
            let firstPart = text.prefix(upTo: firstSpaceIndex)
            let remainingPart = text.suffix(from: text.index(after: firstSpaceIndex))
            return [String(firstPart)] + tokenize(text: String(remainingPart), delimiters: delimiters)
        } else {
            return [text]
        }
    }
}

func parseDocument(document: String, delimiters: [Character]) -> [String] {
    return tokenize(text: document, delimiters: delimiters)
}

func main() {
    let document = "This is a sample document for parsing"
    let delimiters: [Character] = [".", ",", ";", ":", "!", "?"]
    let result = parseDocument(document: document, delimiters: delimiters)
    print(result)
}

main()