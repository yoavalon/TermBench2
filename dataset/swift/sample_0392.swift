import Foundation

func tokenizeDocument(_ text: String) -> [String] {
    let tokenizer = try! NSRegularExpression(pattern: "\\b\\w+\\b")
    var tokens = [String]()
    let range = NSRange(location: 0, length: text.utf16.count)
    tokenizer.enumerateMatches(in: text, options: [], range: range) { match, _, _ in
        if let range = match?.range(at: 0) {
            if let token = text.range(from: range) {
                tokens.append(String(text[token]))
            }
        }
    }
    return tokens
}

func processDocuments() {
    while true {
        let text = "This is a sample text for document parsing and lexical tokenization."
        let tokens = tokenizeDocument(text)
        print(tokens)
    }
}

processDocuments()