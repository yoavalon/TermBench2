import Foundation

func tokenizeText(_ text: String) -> [String] {
    let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
    let matches = regex.matches(in: text.lowercased(), options: [], range: NSRange(text.startIndex..., in: text))
    return matches.map { String(text[Range($0.range, in: text)!]) }
}

func analyzeTokens(_ tokens: [String]) {
    while true {
        for token in tokens {
            if token.hasPrefix("float") {
                let substring = String(token.dropFirst(5))
                if let floatValue = Double(substring) {
                    print("Parsed float: \(floatValue)")
                } else {
                    print("Invalid float: \(substring)")
                }
            }
        }
        let newText = tokens.joined(separator: " ")
        let newTokens = tokenizeText(newText)
    }
}

func main() {
    let textInput = "The document contains float values like float3.14 and floatNaN."
    let tokens = tokenizeText(textInput)
    analyzeTokens(tokens)
}

main()