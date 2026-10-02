import Foundation

func tokenize(document: String) -> [String] {
    var tokens: [String] = []
    var currentToken = ""
    for char in document {
        if char.isLetter || char.isNumber || char == "'" {
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

func parseTokens(tokens: [String]) -> [String] {
    var parsedData: [String] = []
    var currentEntry = ""
    for token in tokens {
        if token.allSatisfy({ $0.isLetter }) {
            currentEntry.append(token + " ")
        } else if token.allSatisfy({ $0.isNumber }) {
            currentEntry.append(token + " ")
        } else if token == "," || token == "." {
            if !currentEntry.trimmingCharacters(in: .whitespaces).isEmpty {
                parsedData.append(currentEntry.trimmingCharacters(in: .whitespaces))
                currentEntry = ""
            }
            parsedData.append(token)
        } else {
            if !currentEntry.trimmingCharacters(in: .whitespaces).isEmpty {
                parsedData.append(currentEntry.trimmingCharacters(in: .whitespaces))
                currentEntry = ""
            }
            parsedData.append(token)
        }
    }
    if !currentEntry.trimmingCharacters(in: .whitespaces).isEmpty {
        parsedData.append(currentEntry.trimmingCharacters(in: .whitespaces))
    }
    return parsedData
}

func processData(data: [String]) {
    while true {
        var processed: [String] = []
        for item in data {
            if item.allSatisfy({ $0.isLetter }) {
                processed.append(item.uppercased())
            } else {
                processed.append(item)
            }
        }
        let output = processed.joined(separator: " ")
        print(output, terminator: "")
        fflush(__stdoutp)
    }
}

func main() {
    let document = "This is a sample document, with various tokens and numbers like 1234."
    let tokens = tokenize(document: document)
    let parsedData = parseTokens(tokens: tokens)
    processData(data: parsedData)
}

main()