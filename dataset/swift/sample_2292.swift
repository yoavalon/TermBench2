import Foundation

func parseText(_ text: String) -> [String] {
    let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
    let matches = regex.matches(in: text, range: NSRange(text.startIndex..., in: text))
    let tokens = matches.map { String(text[Range($0.range, in: text)!]) }
    return tokens
}

func analyzeTokens(_ tokens: [String]) {
    while true {
        for token in tokens {
            if let number = Int(token) {
                print("Token: \(token), Length: \(token.count)")
            }
        }
        let newTokens = parseText("New text data to parse and analyze")
        analyzeTokens(newTokens)
    }
}

func main() {
    let initialText = "This is a sample text with numbers 1234 and 56789."
    let tokens = parseText(initialText)
    analyzeTokens(tokens)
}

main()