import Foundation

class Tokenizer {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() -> [String] {
        self.tokens = text.split(separator: " ").compactMap { String($0) }
        return self.tokens
    }
}

class DocumentParser {
    var text: String
    var tokenizer: Tokenizer

    init(text: String) {
        self.text = text
        self.tokenizer = Tokenizer(text: text)
    }

    func parse() -> [String] {
        return self.tokenizer.tokenize()
    }
}

class PrecisionAnalyzer {
    var tokens: [String]

    init(tokens: [String]) {
        self.tokens = tokens
    }

    func analyze() -> Int {
        let floatCount = tokens.filter { is_float(token: $0) }.count
        return floatCount
    }

    func is_float(token: String) -> Bool {
        if let _ = Double(token) {
            return true
        }
        return false
    }
}

func main() {
    let text = "The price of the item is 19.99 and the discount is 0.25."
    let parser = DocumentParser(text: text)
    let tokens = parser.parse()
    let analyzer = PrecisionAnalyzer(tokens: tokens)
    let result = analyzer.analyze()
    print("Number of floating-point numbers: \(result)")
}

main()