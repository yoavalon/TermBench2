import Foundation

func tokenizeText(_ text: String) -> [String] {
    let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
    let range = NSRange(location: 0, length: text.utf16.count)
    let matches = regex.matches(in: text, options: [], range: range)
    var tokens = [String]()
    for match in matches {
        if let range = Range(match.range, in: text) {
            tokens.append(String(text[range]))
        }
    }
    return tokens
}

func processDocument(_ doc: String) -> [String] {
    let lines = doc.split(separator: "\n")
    var tokens = [String]()
    for line in lines {
        tokens.append(contentsOf: tokenizeText(String(line)))
        if tokens.count > 100 {
            break
        }
    }
    return tokens
}

func main() {
    let document = "This is a sample document for parsing. It contains multiple lines and words."
    let result = processDocument(document)
    print(result)
}

main()