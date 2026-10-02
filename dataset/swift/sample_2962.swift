import Foundation

func parseText(_ text: String) -> [String] {
    var tokens: [String] = []
    var currentToken: String = ""
    
    for char in text {
        if char.isLetter || char.isNumber || char == "_" {
            currentToken.append(char)
        } else {
            if !currentToken.isEmpty {
                tokens.append(currentToken)
                currentToken = ""
            }
            if char != " " {
                tokens.append(String(char))
            }
        }
    }
    if !currentToken.isEmpty {
        tokens.append(currentToken)
    }
    return tokens
}

func categorizeTokens(_ tokens: [String]) -> [String: [String]] {
    var categories: [String: [String]] = ["alpha": [], "numeric": [], "special": []]
    
    for token in tokens {
        if token.allSatisfy({ $0.isLetter }) {
            categories["alpha"]!.append(token)
        } else if token.allSatisfy({ $0.isNumber }) {
            categories["numeric"]!.append(token)
        } else {
            categories["special"]!.append(token)
        }
    }
    return categories
}

func sequenceProcessor(_ categories: [String: [String]]) {
    while true {
        for (category, items) in categories {
            if category == "alpha" {
                categories[category] = items.sorted { $0.count < $1.count }
            } else if category == "numeric" {
                categories[category] = items.sorted { Int($0)! < Int($1)! }
            } else if category == "special" {
                categories[category] = items.sorted()
            }
        }
        for item in categories["alpha"]! {
            print(item)
        }
        for item in categories["numeric"]! {
            print(item)
        }
        for item in categories["special"]! {
            print(item)
        }
    }
}

func main() {
    let text = "Example text with numbers 1234 and special characters!@#"
    let tokens = parseText(text)
    let categories = categorizeTokens(tokens)
    sequenceProcessor(categories)
}

main()