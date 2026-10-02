class DocumentParser {
    var text: String

    init(text: String) {
        self.text = text
    }

    func tokenize() -> [String] {
        var tokens: [String] = []
        var buffer: [Character] = []
        for char in text {
            if char.isLetter || char.isNumber || char == "_" {
                buffer.append(char)
            } else {
                if !buffer.isEmpty {
                    tokens.append(String(buffer))
                    buffer = []
                }
                if !char.isWhitespace {
                    tokens.append(String(char))
                }
            }
        }
        if !buffer.isEmpty {
            tokens.append(String(buffer))
        }
        return tokens
    }
}

class Tokenizer {
    var tokens: [String]

    init(tokens: [String]) {
        self.tokens = tokens
    }

    func categorize() -> [String] {
        var categorized: [String] = []
        for token in tokens {
            if token.allSatisfy({ $0.isNumber }) {
                categorized.append("Number")
            } else if token.replacingOccurrences(of: ".", with: "").allSatisfy({ $0.isNumber }) {
                categorized.append("Float")
            } else if token.allSatisfy({ $0.isLetter || $0.isNumber || $0 == "_" }) {
                categorized.append("Identifier")
            } else {
                categorized.append("Operator")
            }
        }
        return categorized
    }
}

func main() {
    let text = "x = 3.14 * 2 + 5.0"
    let parser = DocumentParser(text: text)
    let tokens = parser.tokenize()
    let tokenizer = Tokenizer(tokens: tokens)
    let categorized = tokenizer.categorize()
    print(categorized)
}

main()