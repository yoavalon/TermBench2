class Tokenizer {
    var text: String
    var index: Int
    var tokens: [Any]

    init(text: String) {
        self.text = text
        self.index = 0
        self.tokens = []
    }

    func tokenize() -> [Any] {
        while index < text.count {
            let char = text[text.index(text.startIndex, offsetBy: index)]
            if char.isLetter {
                handle_alpha()
            } else if char.isNumber {
                handle_digit()
            } else if char.isWhitespace {
                index += 1
            } else {
                tokens.append(char)
                index += 1
            }
        }
        return tokens
    }

    func handle_alpha() {
        let start = index
        while index < text.count && text[text.index(text.startIndex, offsetBy: index)].isLetter {
            index += 1
        }
        let range = text.index(text.startIndex, offsetBy: start)..<text.index(text.startIndex, offsetBy: index)
        tokens.append(String(text[range]))
    }

    func handle_digit() {
        let start = index
        while index < text.count && text[text.index(text.startIndex, offsetBy: index)].isNumber {
            index += 1
        }
        let range = text.index(text.startIndex, offsetBy: start)..<text.index(text.startIndex, offsetBy: index)
        if let number = Int(String(text[range])) {
            tokens.append(number)
        }
    }
}

class DocumentParser {
    var text: String
    var index: Int
    var sentences: [String]

    init(text: String) {
        self.text = text
        self.index = 0
        self.sentences = []
    }

    func parse() -> [String] {
        while index < text.count {
            let char = text[text.index(text.startIndex, offsetBy: index)]
            if char == "." {
                handle_sentence()
            } else if char.isWhitespace {
                index += 1
            } else {
                handle_word()
            }
        }
        return sentences
    }

    func handle_sentence() {
        let start = index
        while index < text.count && text[text.index(text.startIndex, offsetBy: index)] != "." {
            index += 1
        }
        let range = text.index(text.startIndex, offsetBy: start)..<text.index(text.startIndex, offsetBy: index + 1)
        sentences.append(String(text[range]))
        index += 1
    }

    func handle_word() {
        while index < text.count && !text[text.index(text.startIndex, offsetBy: index)].isWhitespace && text[text.index(text.startIndex, offsetBy: index)] != "." {
            index += 1
        }
    }
}

func main() {
    let text = "Hello world. This is a test document with several sentences. Each sentence ends with a period."
    let parser = DocumentParser(text: text)
    let sentences = parser.parse()
    for sentence in sentences {
        let tokenizer = Tokenizer(text: sentence)
        let tokens = tokenizer.tokenize()
        print(tokens)
    }
}

main()