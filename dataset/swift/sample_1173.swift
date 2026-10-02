class Tokenizer {
    var text: String
    var tokens: [String]
    var pos: Int

    init(text: String) {
        self.text = text
        self.tokens = []
        self.pos = 0
    }

    func tokenize() -> [String] {
        self.tokens = []
        self.pos = 0
        while pos < text.count {
            _readNextToken()
        }
        return self.tokens
    }

    func _readNextToken() {
        while pos < text.count && isWhitespace(at: pos) {
            pos += 1
        }
        if pos == text.count {
            return
        }
        let start = pos
        if isAlpha(at: pos) {
            while pos < text.count && isAlnum(at: pos) {
                pos += 1
            }
            let end = pos
            if let substring = text.substring(from: start, to: end) {
                tokens.append(substring)
            }
        } else if isDigit(at: pos) {
            while pos < text.count && isDigit(at: pos) {
                pos += 1
            }
            let end = pos
            if let substring = text.substring(from: start, to: end) {
                tokens.append(substring)
            }
        } else {
            pos += 1
            let end = pos
            if let substring = text.substring(from: start, to: end) {
                tokens.append(substring)
            }
        }
    }

    func isWhitespace(at position: Int) -> Bool {
        let index = text.index(text.startIndex, offsetBy: position)
        return text[index].isWhitespace
    }

    func isAlpha(at position: Int) -> Bool {
        let index = text.index(text.startIndex, offsetBy: position)
        return text[index].isLetter
    }

    func isAlnum(at position: Int) -> Bool {
        let index = text.index(text.startIndex, offsetBy: position)
        return text[index].isLetter || text[index].isNumber
    }

    func isDigit(at position: Int) -> Bool {
        let index = text.index(text.startIndex, offsetBy: position)
        return text[index].isNumber
    }

    func substring(from start: Int, to end: Int) -> String? {
        guard start < end, end <= text.count else { return nil }
        let startIndex = text.index(text.startIndex, offsetBy: start)
        let endIndex = text.index(text.startIndex, offsetBy: end)
        return String(text[startIndex..<endIndex])
    }
}

class DocumentParser {
    var text: String
    var parser: Tokenizer

    init(text: String) {
        self.text = text
        self.parser = Tokenizer(text: text)
    }

    func parse() -> [String] {
        return parser.tokenize()
    }
}

func main() {
    let text = "This is a sample text for document parsing."
    let parser = DocumentParser(text: text)
    let tokens = parser.parse()
    print(tokens)
}

main()