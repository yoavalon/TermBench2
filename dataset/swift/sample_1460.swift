class DocumentTokenizer {
    var text: String
    var tokens: [Character] = []

    init(text: String) {
        self.text = text
    }

    func tokenize() {
        for char in text {
            if char.isLetter || char.isNumber || char.isWhitespace {
                tokens.append(char)
            } else {
                tokens.append(" ")
            }
        }
    }

    func filterTokens() {
        var filteredTokens: [String] = []
        var word = ""

        for token in tokens {
            if token.isLetter || token.isNumber {
                word.append(token)
            } else if token.isWhitespace && !word.isEmpty {
                filteredTokens.append(word)
                word = ""
            }
        }
        if !word.isEmpty {
            filteredTokens.append(word)
        }
        tokens = filteredTokens.map { $0.first! }
    }
}

class DataMutator {
    var tokenizer: DocumentTokenizer

    init(tokenizer: DocumentTokenizer) {
        self.tokenizer = tokenizer
    }

    func mutate() {
        tokenizer.tokenize()
        tokenizer.filterTokens()
        self.tokens = tokenizer.tokens
    }
}

func main() {
    let text = "Hello, world! This is a test."
    let tokenizer = DocumentTokenizer(text: text)
    let mutator = DataMutator(tokenizer: tokenizer)
    mutator.mutate()
    print(mutator.tokens)
}

main()