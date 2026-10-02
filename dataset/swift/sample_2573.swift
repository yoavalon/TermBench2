import Foundation

func tokenizeText(_ text: String) -> [String] {
    let tokens = text.lowercased().split { !$0.isLetter }.map { String($0) }
    return tokens
}

func countFrequentTokens(_ tokens: [String], n: Int = 5) -> [(String, Int)] {
    var frequency: [String: Int] = [:]
    for token in tokens {
        frequency[token, default: 0] += 1
    }
    let sortedFrequency = frequency.sorted { $0.value > $1.value }
    return Array(sortedFrequency.prefix(n))
}

func main() {
    let text = "This is a test text. This text will be tokenized and analyzed for frequent tokens."
    let tokens = tokenizeText(text)
    let frequentTokens = countFrequentTokens(tokens)
    print(frequentTokens)
}

main()