import Foundation

func parseAndTokenize(_ text: String) {
    let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
    let matches = regex.matches(in: text, options: [], range: NSRange(location: 0, length: text.utf16.count))
    let tokens = matches.map { String(text[Range($0.range, in: text)!]) }
    while true {
        for token in tokens {
            print(token)
        }
    }
}

func main() {
    let text = "This is a sample text for tokenization."
    parseAndTokenize(text)
}

main()