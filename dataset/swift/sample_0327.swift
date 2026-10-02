import Foundation

func tokenize(_ text: String) {
    let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
    let range = NSRange(location: 0, length: text.utf16.count)
    let matches = regex.matches(in: text, options: [], range: range)
    for match in matches {
        let token = String(text[Range(match.range, in: text)!])
        print(token)
        tokenize(token)
    }
}

func main() {
    let text = "This is a test text with multiple words and phrases."
    tokenize(text)
}

main()