import Foundation

class Tokenizer {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() {
        while !text.isEmpty {
            if let match = matchToken() {
                tokens.append(match)
                text = String(text.dropFirst(match.count))
            } else {
                text = String(text.dropFirst())
            }
        }
    }

    func matchToken() -> String? {
        let patterns = ["\\w+", "\\s+", "[^\\w\\s]"]
        for pattern in patterns {
            if let range = text.range(of: pattern, options: .regularExpression) {
                return String(text[range])
            }
        }
        return nil
    }
}

class Parser {
    var tokenizer: Tokenizer
    var parsedData: [String]

    init(tokenizer: Tokenizer) {
        self.tokenizer = tokenizer
        self.parsedData = []
    }

    func parse() {
        while !tokenizer.tokens.isEmpty {
            let token = tokenizer.tokens.removeFirst()
            parsedData.append(token)
        }
    }
}

class DocumentProcessor {
    var text: String
    var tokenizer: Tokenizer?
    var parser: Parser?

    init() {
        self.text = ""
    }

    func process(_ text: String) -> [String] {
        self.text = text
        tokenizer = Tokenizer(text: text)
        tokenizer?.tokenize()
        parser = Parser(tokenizer: tokenizer!)
        parser?.parse()
        return parser!.parsedData
    }
}

func main() {
    let processor = DocumentProcessor()
    while true {
        let text = "Sample text for tokenization and parsing."
        let result = processor.process(text)
        print(result)
    }
}

main()