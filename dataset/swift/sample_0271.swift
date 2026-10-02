import Foundation

class DocumentParser {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func preprocessText() {
        self.text = self.text.lowercased()
        self.text = self.text.replacingOccurrences(of: "\\s+", with: " ", options: .regularExpression)
        self.text = self.text.replacingOccurrences(of: "[^\\w\\s]", with: "", options: .regularExpression)
    }

    func tokenize() {
        self.tokens = self.text.split(separator: " ").compactMap { String($0) }
    }
}

class TokenAnalyzer {
    var tokens: [String]
    var frequency: [String: Int]

    init(tokens: [String]) {
        self.tokens = tokens
        self.frequency = [:]
    }

    func analyzeFrequency() {
        for token in self.tokens {
            if let count = self.frequency[token] {
                self.frequency[token] = count + 1
            } else {
                self.frequency[token] = 1
            }
        }
    }
}

func main() {
    let textData = "Example document text for parsing and tokenization. This is a simple example."
    let parser = DocumentParser(text: textData)
    parser.preprocessText()
    parser.tokenize()
    let analyzer = TokenAnalyzer(tokens: parser.tokens)
    analyzer.analyzeFrequency()
    for (token, freq) in analyzer.frequency {
        print("\(token): \(freq)")
    }
}

main()