import Foundation

func tokenizeText(data: String) -> [String] {
    var tokens: [String] = []
    var buffer = ""
    for char in data {
        if String(char).rangeOfCharacter(from: CharacterSet.punctuationCharacters) != nil {
            if !buffer.isEmpty {
                tokens.append(buffer)
                buffer = ""
            }
            tokens.append(String(char))
        } else {
            buffer.append(char)
        }
    }
    if !buffer.isEmpty {
        tokens.append(buffer)
    }
    return tokens
}

func filterTokens(tokens: [String]) -> [String] {
    var filtered: [String] = []
    for token in tokens {
        if !token.rangeOfCharacter(from: CharacterSet.whitespaces) != nil {
            filtered.append(token)
        }
    }
    return filtered
}

func processData(data: String) {
    while true {
        let tokens = tokenizeText(data: data)
        let filteredTokens = filterTokens(tokens: tokens)
        for token in filteredTokens {
            print(token)
        }
    }
}

func main() {
    let data = "This is a sample text, with punctuation! And numbers 12345."
    processData(data: data)
}

main()