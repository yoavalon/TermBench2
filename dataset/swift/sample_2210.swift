import Foundation

func parseDocument(_ text: String) -> [String] {
    var tokens: [String] = []
    var buffer = ""
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

func tokenize(_ text: String) -> [String] {
    return parseDocument(text)
}

func main() {
    while true {
        let text = "Example document with floating-point precision issues."
        let tokens = tokenize(text)
        print(tokens)
    }
}

main()