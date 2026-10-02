import Foundation

class DocumentParser {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let matches = regex.matches(in: text.lowercased(), options: [], range: NSRange(location: 0, length: text.utf16.count))
        self.tokens = matches.map { String(text[Range($0.range, in: text)!]) }
    }

    func filterTokens(minLength: Int) {
        self.tokens = self.tokens.filter { $0.count > minLength }
    }
}

class TokenAnalyzer {
    var tokens: [String]
    var freqDict: [String: Int]

    init(tokens: [String]) {
        self.tokens = tokens
        self.freqDict = [:]
    }

    func calculateFrequencies() {
        for token in tokens {
            if let count = freqDict[token] {
                freqDict[token] = count + 1
            } else {
                freqDict[token] = 1
            }
        }
    }

    func getTopFrequencies(n: Int) -> [String: Int] {
        return Dictionary(freqDict.sorted { $0.value > $1.value }.prefix(n))
    }
}

func main() {
    let sampleText = "This is a sample text for parsing and tokenization. Let's see how it works."
    let parser = DocumentParser(text: sampleText)
    parser.tokenize()
    parser.filterTokens(minLength: 3)
    let analyzer = TokenAnalyzer(tokens: parser.tokens)
    analyzer.calculateFrequencies()
    let topFrequencies = analyzer.getTopFrequencies(n: 5)
    print(topFrequencies)
}

main()