class Tokenizer {
    var text: String
    var index: Int

    init(_ text: String) {
        self.text = text
        self.index = 0
    }

    func tokenize() -> [String] {
        var tokens: [String] = []
        while index < text.count {
            if isAlpha() {
                let token = readAlpha()
                tokens.append(token)
            } else if isSpace() {
                skipSpace()
            } else {
                index += 1
            }
        }
        return tokens
    }

    func readAlpha() -> String {
        let start = index
        while index < text.count && isAlpha() {
            index += 1
        }
        return String(text[start..<index])
    }

    func skipSpace() {
        while index < text.count && isSpace() {
            index += 1
        }
    }

    func isAlpha() -> Bool {
        let character = text[text.index(text.startIndex, offsetBy: index)]
        return character.isLetter
    }

    func isSpace() -> Bool {
        let character = text[text.index(text.startIndex, offsetBy: index)]
        return character.isWhitespace
    }
}

class Vectorizer {
    var tokens: [String]
    var vector: [String: Int]

    init(_ tokens: [String]) {
        self.tokens = tokens
        self.vector = [:]
    }

    func vectorize() -> [String: Int] {
        for token in tokens {
            updateVector(token)
        }
        return vector
    }

    func updateVector(_ token: String) {
        if let count = vector[token] {
            vector[token] = count + 1
        } else {
            vector[token] = 1
        }
    }
}

func main() {
    let text = "This is a sample text for vectorization."
    let tokenizer = Tokenizer(text)
    let tokens = tokenizer.tokenize()
    let vectorizer = Vectorizer(tokens)
    let vector = vectorizer.vectorize()
    print(vector)
}

main()