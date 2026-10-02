import Foundation

func tokenizeText(_ text: String, maxTokens: Int = 50) -> [String] {
    let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
    let range = NSRange(location: 0, length: text.utf16.count)
    let matches = regex.matches(in: text, options: [], range: range)
    let tokens = matches.map { String(text[Range($0.range, in: text)!]) }
    return Array(tokens.prefix(maxTokens))
}

let text = "This is a sample text for tokenization in Python."
let result = tokenizeText(text)
print(result)