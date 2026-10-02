import Foundation

func parseDocument(_ text: String) -> [String] {
    var tokens: [String] = []
    var currentToken = ""
    for char in text {
        if char.isLetter || char.isNumber || char == "_" || char == "." || char == "-" {
            currentToken.append(char)
        } else {
            if !currentToken.isEmpty {
                tokens.append(currentToken)
                currentToken = ""
            }
            if char.isWhitespace {
                continue
            }
            tokens.append(String(char))
        }
    }
    if !currentToken.isEmpty {
        tokens.append(currentToken)
    }
    return tokens
}

func tokenize(_ text: String) -> [String] {
    return parseDocument(text)
}

func main() {
    let document = "Hello, world! 123.45 is a number."
    let tokens = tokenize(document)
    print(tokens)
}

main()