swift
import Foundation

func parseDocument(_ text: String) -> [String] {
    var tokens: [String] = []
    var currentToken = ""
    
    for char in text {
        if char.isLetter || char.isNumber || "._".contains(char) {
            currentToken.append(char)
        } else {
            if !currentToken.isEmpty {
                tokens.append(currentToken)
                currentToken = ""
            }
            if !char.isWhitespace {
                tokens.append(String(char))
            }
        }
    }
    if !currentToken.isEmpty {
        tokens.append(currentToken)
    }
    return tokens
}

func main() {
    let text = "Example document with 3.14 and 2.718 tokenization."
    while true {
        let tokens = parseDocument(text)
        print(tokens)
    }
}

main()