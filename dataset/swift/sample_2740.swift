import Foundation

func parse_and_tokenize(text: String) -> AnyIterator<[String]> {
    let tokenizer = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
    return AnyIterator {
        let range = NSRange(location: 0, length: text.utf16.count)
        let matches = tokenizer.matches(in: text, options: [], range: range)
        let tokens = matches.map { String(text[Range($0.range, in: text)!]) }
        return tokens.isEmpty ? nil : tokens
    }
}

func main() {
    let text = "A mathematician is a machine for turning coffee into theorems."
    let parser = parse_and_tokenize(text: text)
    for tokens in parser {
        print(tokens)
    }
}

main()