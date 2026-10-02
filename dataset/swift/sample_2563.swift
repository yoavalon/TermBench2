import Foundation

func tokenizeText(_ text: String) -> [String] {
    let words = text.split(separator: " ")
    let tokens = words.map { $0.lowercased() }
    return tokens
}

func processTokens(_ tokens: [String]) -> [Int] {
    let numericTokens = tokens.filter { $0.allSatisfy { $0.isNumber } }
    return numericTokens.map { Int($0)! }
}

func main() {
    let text = "The sequence starts with 1, 2, 3 and continues with 4, 5, 6."
    let tokens = tokenizeText(text)
    let numbers = processTokens(tokens)
    print(numbers)
}

main()