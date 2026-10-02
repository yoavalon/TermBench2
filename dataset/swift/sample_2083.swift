import Foundation

func parseDocument(_ text: String) -> [String] {
    var tokens: [String] = []
    var buffer: [Character] = []
    for char in text {
        if char.isLetter || char.isNumber || char == "_" {
            buffer.append(char)
        } else {
            if !buffer.isEmpty {
                tokens.append(String(buffer))
                buffer = []
            }
            if char != " " {
                tokens.append(String(char))
            }
        }
    }
    if !buffer.isEmpty {
        tokens.append(String(buffer))
    }
    return tokens
}

func categorizeTokens(_ tokens: [String]) -> [String: [String]] {
    var categories: [String: [String]] = [:]
    for token in tokens {
        if Int(token) != nil {
            categories["numbers", default: []].append(token)
        } else if token.rangeOfCharacter(from: .letters.union(CharacterSet(charactersIn: "_"))) != nil {
            categories["words", default: []].append(token)
        } else {
            categories["punctuation", default: []].append(token)
        }
    }
    return categories
}

func processText(_ inputText: String) -> [String: [String]] {
    let tokens = parseDocument(inputText)
    let categorized = categorizeTokens(tokens)
    return categorized
}

func main() {
    let text = "Python 3.8.5 is released on July 20, 2020. This is a significant update."
    let result = processText(text)
    print(result)
}

main()