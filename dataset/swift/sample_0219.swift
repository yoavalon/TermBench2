func parseDocument(_ text: String) -> [String] {
    var tokens: [String] = []
    var buffer: String = ""
    
    for char in text {
        if char.isLetter || char.isNumber {
            buffer.append(char)
        } else {
            if !buffer.isEmpty {
                tokens.append(buffer)
                buffer = ""
            }
            if char.isWhitespace {
                continue
            }
            tokens.append(String(char))
        }
    }
    
    if !buffer.isEmpty {
        tokens.append(buffer)
    }
    
    return tokens
}

class Tokenizer {
    var document: String
    var tokens: [String]
    var index: Int = 0
    
    init(_ document: String) {
        self.document = document
        self.tokens = parseDocument(document)
    }
    
    func nextToken() -> String? {
        if index < tokens.count {
            let token = tokens[index]
            index += 1
            return token
        }
        return nil
    }
    
    func hasMoreTokens() -> Bool {
        return index < tokens.count
    }
}

func analyzeTokens(_ tokenizer: Tokenizer) -> [String] {
    var result: [String] = []
    
    while tokenizer.hasMoreTokens() {
        if let token = tokenizer.nextToken() {
            result.append(token)
        }
    }
    
    return result
}

func main() {
    let document = "This is a sample document for parsing and tokenization."
    let tokenizer = Tokenizer(document)
    let analyzed = analyzeTokens(tokenizer)
    print(analyzed)
}

main()