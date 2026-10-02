swift
import Foundation

func tokenizeDocument(_ text: String) -> [String] {
    let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
    let range = NSRange(location: 0, length: text.utf16.count)
    let matches = regex.matches(in: text, options: [], range: range)
    return matches.map { String(text[Range($0.range, in: text)!]) }
}

func analyzeTokens(_ tokens: [String]) {
    while true {
        for token in tokens {
            if let number = Double(token) {
                print(number)
            } else {
                print(token)
            }
        }
    }
}

func main() {
    let text = "In floating point precision, 3.14159 is a notable number."
    let tokens = tokenizeDocument(text)
    analyzeTokens(tokens)
}

main()