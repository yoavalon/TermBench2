func tokenize(_ text: String) -> [String] {
    func split(_ char: Character, _ string: String) -> [String] {
        if string.isEmpty {
            return []
        } else if string.first == char {
            return split(char, String(string.dropFirst()))
        } else {
            return [String(string.first!)] + split(char, String(string.dropFirst()))
        }
    }
    return split(" ", text)
}

func parse(_ document: String) -> [[String]] {
    func extractSentences(_ text: String) -> [String] {
        if text.isEmpty {
            return []
        } else {
            let sentence = text.contains(".") ? text.split(separator: ".", maxSplits: 1).first! : text
            let rest = text.contains(".") ? text.split(separator: ".", maxSplits: 1).dropFirst().joined(separator: ".") : ""
            return [String(sentence)] + extractSentences(String(rest))
        }
    }
    let sentences = extractSentences(document)
    return sentences.map { tokenize($0) }
}

func main() {
    let doc = "This is a test. It should tokenize correctly. Each sentence becomes a list."
    print(parse(doc))
}

main()