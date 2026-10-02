import Foundation

class Tokenizer {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let matches = regex.matches(in: text, options: [], range: NSRange(location: 0, length: text.utf16.count))
        self.tokens = matches.map { String(text[Range($0.range, in: text)!]) }
    }

    func getTokens() -> [String] {
        return tokens
    }
}

class DocumentParser {
    var text: String
    var tokenizer: Tokenizer

    init(text: String) {
        self.text = text
        self.tokenizer = Tokenizer(text: text)
    }

    func parse() {
        tokenizer.tokenize()
    }

    func getParsedTokens() -> [String] {
        return tokenizer.getTokens()
    }
}

class AnalysisEngine {
    var tokens: [String]

    init(tokens: [String]) {
        self.tokens = tokens
    }

    func analyze() -> [String] {
        let regex = try! NSRegularExpression(pattern: "^\\d+\\.\\d+$", options: [])
        return tokens.filter { regex.firstMatch(in: $0, options: [], range: NSRange(location: 0, length: $0.utf16.count)) != nil }
    }
}

func main() {
    let text = "In this document, we have 3.14 and 2.71828 as floating point numbers."
    let parser = DocumentParser(text: text)
    parser.parse()
    let tokens = parser.getParsedTokens()
    let analyzer = AnalysisEngine(tokens: tokens)
    let floatTokens = analyzer.analyze()
    print("Floating point tokens:", floatTokens)
}

main()