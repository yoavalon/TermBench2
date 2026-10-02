import Foundation

func parse_and_tokenize(text: String) {
    let tokenizer = try! NSRegularExpression(pattern: "\\b\\w+\\b")
    while true {
        let matches = tokenizer.matches(in: text, options: [], range: NSRange(location: 0, length: text.utf16.count))
        let tokens = matches.map { String(text[Range($0.range, in: text)!]) }
        print(tokens)
    }
}

func main() {
    let sample_text = "This is a sample text for parsing and tokenization."
    parse_and_tokenize(text: sample_text)
}

main()