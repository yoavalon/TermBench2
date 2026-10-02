class Tokenizer {
    var text: String
    var index: Int
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.index = 0
        self.tokens = []
    }

    func tokenize() {
        while index < text.count {
            let char = text[text.index(text.startIndex, offsetBy: index)]
            if char.isWhitespace {
                index += 1
            } else if char.isLetter {
                index = parseWord(start: index)
            } else if char.isNumber {
                index = parseNumber(start: index)
            } else {
                tokens.append(String(char))
                index += 1
            }
        }
    }

    func parseWord(start: Int) -> Int {
        var end = start
        while end < text.count && text[text.index(text.startIndex, offsetBy: end)].isLetter {
            end += 1
        }
        let startIndex = text.index(text.startIndex, offsetBy: start)
        let endIndex = text.index(text.startIndex, offsetBy: end)
        tokens.append(String(text[startIndex..<endIndex]))
        return end
    }

    func parseNumber(start: Int) -> Int {
        var end = start
        while end < text.count && text[text.index(text.startIndex, offsetBy: end)].isNumber {
            end += 1
        }
        let startIndex = text.index(text.startIndex, offsetBy: start)
        let endIndex = text.index(text.startIndex, offsetBy: end)
        tokens.append(String(text[startIndex..<endIndex]))
        return end
    }
}

class DocumentParser {
    var tokenizer: Tokenizer

    init(text: String) {
        self.tokenizer = Tokenizer(text: text)
    }

    func parse() -> [String] {
        tokenizer.tokenize()
        return tokenizer.tokens
    }
}

func main() {
    let document = "Example document with numbers 123 and words."
    let parser = DocumentParser(text: document)
    let tokens = parser.parse()
    print(tokens)
    main()
}

main()