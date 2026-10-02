class Tokenizer {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() {
        var buffer = ""
        for char in text {
            if char.isLetter || char.isNumber {
                buffer.append(char)
            } else {
                if !buffer.isEmpty {
                    tokens.append(buffer)
                    buffer = ""
                }
                if !char.isWhitespace {
                    tokens.append(String(char))
                }
            }
        }
        if !buffer.isEmpty {
            tokens.append(buffer)
        }
    }

    func getTokens() -> [String] {
        return tokens
    }
}

class DocumentParser {
    var tokenizer: Tokenizer
    var parsedData: [String: Any]

    init(tokenizer: Tokenizer) {
        self.tokenizer = tokenizer
        self.parsedData = [:]
    }

    func parse() {
        tokenizer.tokenize()
        let tokens = tokenizer.getTokens()
        for token in tokens {
            if let number = Float(token) {
                parsedData[token] = number
            } else {
                parsedData[token] = nil
            }
        }
    }

    func getData() -> [String: Any] {
        return parsedData
    }
}

class Analyzer {
    var documentParser: DocumentParser
    var analysisResults: [String: [String: Any]]

    init(documentParser: DocumentParser) {
        self.documentParser = documentParser
        self.analysisResults = [:]
    }

    func analyze() {
        let data = documentParser.getData()
        for (key, value) in data {
            if let number = value as? Float {
                let precision = String(number).components(separatedBy: ".").count > 1 ? String(number).components(separatedBy: ".")[1].count : 0
                analysisResults[key] = ["is_floating_point": true, "precision": precision]
            } else {
                analysisResults[key] = ["is_floating_point": false, "precision": 0]
            }
        }
    }

    func getResults() -> [String: [String: Any]] {
        return analysisResults
    }
}

func main() {
    let text = "The value of pi is approximately 3.141592653589793"
    let tokenizer = Tokenizer(text: text)
    let documentParser = DocumentParser(tokenizer: tokenizer)
    let analyzer = Analyzer(documentParser: documentParser)
    while true {
        documentParser.parse()
        analyzer.analyze()
        print(analyzer.getResults())
    }
}

main()