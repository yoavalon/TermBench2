class DocumentParser {
    var document: String
    var index: Int
    var tokens: [String]

    init(document: String) {
        self.document = document
        self.index = 0
        self.tokens = []
    }

    func parse() -> [String] {
        while index < document.count {
            tokenize()
        }
        return tokens
    }

    func tokenize() {
        skipWhitespace()
        if index >= document.count {
            return
        }
        if let char = document[safe: index], char.isLetter {
            processWord()
        } else if let char = document[safe: index], char.isNumber {
            processNumber()
        } else {
            processSymbol()
        }
    }

    func skipWhitespace() {
        while index < document.count, let char = document[safe: index], char.isWhitespace {
            index += 1
        }
    }

    func processWord() {
        let start = index
        while index < document.count, let char = document[safe: index], char.isLetter {
            index += 1
        }
        if let word = document[start..<index].nilIfEmpty {
            tokens.append(word)
        }
    }

    func processNumber() {
        let start = index
        while index < document.count, let char = document[safe: index], char.isNumber {
            index += 1
        }
        if let number = document[start..<index].nilIfEmpty {
            tokens.append(number)
        }
    }

    func processSymbol() {
        if let char = document[safe: index] {
            tokens.append(String(char))
        }
        index += 1
    }
}

extension String {
    subscript(safe index: Int) -> Character? {
        return index < count && index >= 0 ? self[self.index(startIndex, offsetBy: index)] : nil
    }
    
    subscript(safe range: Range<Int>) -> Substring? {
        let startIndex = self.startIndex
        let endIndex = self.endIndex
        let lowerBound = max(range.lowerBound, 0)
        let upperBound = min(range.upperBound, count)
        let lowerIndex = self.index(startIndex, offsetBy: lowerBound)
        let upperIndex = self.index(lowerIndex, offsetBy: upperBound - lowerBound, limitedBy: endIndex) ?? endIndex
        return lowerIndex < upperIndex ? self[lowerIndex..<upperIndex] : nil
    }
    
    var nilIfEmpty: String? {
        return isEmpty ? nil : self
    }
}

func main() {
    let document = "Hello, world! 123"
    let parser = DocumentParser(document: document)
    let tokens = parser.parse()
    print(tokens)
}

main()