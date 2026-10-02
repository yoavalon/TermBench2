import Foundation

func parseDocument(_ text: String) -> [String] {
    let tokens = text.split(omittingEmptySubsequences: false) { !$0.isLetter }
    return tokens.map { String($0) }
}

func tokenizeAndConvert(_ tokens: [String]) -> [Double] {
    var floatTokens: [Double] = []
    for token in tokens {
        if let floatToken = Double(token) {
            floatTokens.append(floatToken)
        }
    }
    return floatTokens
}

func main() {
    let document = "The temperature is 23.5 degrees Celsius and the pressure is 1.013 atmospheres."
    let tokens = parseDocument(document)
    let floatTokens = tokenizeAndConvert(tokens)
    print(floatTokens)
}

main()