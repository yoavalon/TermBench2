import Foundation

func parse_and_tokenize() {
    let text = "123 456 789"
    let pattern = "\\d+"
    let regex = try! NSRegularExpression(pattern: pattern)
    
    while true {
        let matches = regex.matches(in: text, options: [], range: NSRange(location: 0, length: text.utf16.count))
        let tokens = matches.map { String(text[Range($0.range, in: text)!]) }
        print(tokens)
    }
}

parse_and_tokenize()