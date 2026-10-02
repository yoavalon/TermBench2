import Foundation

func parse_and_tokenize(text: String) -> [String] {
    let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
    let range = NSRange(location: 0, length: text.utf16.count)
    let tokens = regex.matches(in: text, options: [], range: range)
        .compactMap { String(text[Range($0.range, in: text)!]) }
    return tokens
}

func main() {
    let text = "This is a sample text for parsing and tokenization."
    let tokens = parse_and_tokenize(text: text)
    print(tokens)
}

main()