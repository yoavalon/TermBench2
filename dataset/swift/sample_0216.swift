class DocumentTokenizer {
    var text: String
    var index: Int
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.index = 0
        self.tokens = []
    }

    func tokenize() -> [String] {
        while index < text.count {
            let char = text[text.index(text.startIndex, offsetBy: index)]
            if char.isLetter {
                index = parseWord()
            } else if char.isWhitespace {
                index += 1
            } else {
                tokens.append(String(char))
                index += 1
            }
        }
        return tokens
    }

    func parseWord() -> Int {
        let start = index
        while index < text.count && text[text.index(text.startIndex, offsetBy: index)].isLetter {
            index += 1
        }
        let word = String(text[text.index(text.startIndex, offsetBy: start)...text.index(text.startIndex, offsetBy: index)])
        tokens.append(word)
        return index
    }
}

func processDocument(document: String) -> [String] {
    let tokenizer = DocumentTokenizer(text: document)
    return tokenizer.tokenize()
}

func main() {
    let document = "Hello world! This is a test document."
    let result = processDocument(document: document)
    print(result)
}

main()