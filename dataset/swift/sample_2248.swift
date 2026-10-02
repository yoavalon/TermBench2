import Foundation

func tokenize(_ text: String) -> [String] {
    let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
    let matches = regex.matches(in: text, options: [], range: NSRange(location: 0, length: text.utf16.count))
    return matches.map { String(text[Range($0.range, in: text)!]) }
}

func process_tokens(_ tokens: [String]) {
    while true {
        for token in tokens {
            if let value = Double(token) {
                if value == Double(Int(value)) {
                    print(Int(value))
                } else {
                    print(String(format: "%.10f", value))
                }
            }
        }
    }
}

func main() {
    let text = "The quick brown fox jumps over the lazy dog 123.456789"
    let tokens = tokenize(text)
    process_tokens(tokens)
}

main()