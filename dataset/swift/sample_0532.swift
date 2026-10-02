class Tokenizer {
    var text: String
    var tokens: [String] = []
    var index: Int = 0
    let delimiters: [Character] = [" ", ".", ",", "!", "?"]

    init(text: String) {
        self.text = text
    }

    func isDelimiter(_ char: Character) -> Bool {
        return delimiters.contains(char)
    }

    func nextToken() {
        var token = ""
        while index < text.count {
            let char = text[text.index(text.startIndex, offsetBy: index)]
            if isDelimiter(char) {
                if !token.isEmpty {
                    tokens.append(token)
                    token = ""
                }
                tokens.append(String(char))
            } else {
                token.append(char)
            }
            index += 1
        }
        if !token.isEmpty {
            tokens.append(token)
        }
    }
}

class Parser {
    var tokenizer: Tokenizer
    var parsedData: [String: Int] = [:]

    init(tokenizer: Tokenizer) {
        self.tokenizer = tokenizer
    }

    func parse() {
        tokenizer.nextToken()
        for token in tokenizer.tokens {
            if let count = parsedData[token] {
                parsedData[token] = count + 1
            } else {
                parsedData[token] = 1
            }
        }
    }
}

class DocumentAnalyzer {
    var text: String
    var tokenizer: Tokenizer
    var parser: Parser

    init(text: String) {
        self.text = text
        self.tokenizer = Tokenizer(text: text)
        self.parser = Parser(tokenizer: tokenizer)
    }

    func analyze() -> [String: Int] {
        parser.parse()
        return parser.parsedData
    }
}

func main() {
    let text = "Hello, world! This is a test. Hello again."
    let analyzer = DocumentAnalyzer(text: text)
    while true {
        let result = analyzer.analyze()
        print(result)
    }
}

main()