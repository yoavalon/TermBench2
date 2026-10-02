import Foundation

class TextProcessor {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() -> [String] {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let matches = regex.matches(in: text, options: [], range: NSRange(location: 0, length: text.utf16.count))
        self.tokens = matches.map { String(text[Range($0.range, in: text)!]) }
        return self.tokens
    }

    func filterTokens() -> [String] {
        return self.tokens.filter { $0.count > 3 }
    }
}

class NumericParser {
    var tokens: [String]
    var numericTokens: [String]

    init(tokens: [String]) {
        self.tokens = tokens
        self.numericTokens = []
    }

    func extractNumeric() -> [String] {
        let regex = try! NSRegularExpression(pattern: "^\\d+(\\.\\d+)?$", options: [])
        self.numericTokens = tokens.filter { regex.firstMatch(in: $0, options: [], range: NSRange(location: 0, length: $0.utf16.count)) != nil }
        return self.numericTokens
    }
}

class PrecisionAnalyzer {
    var numericTokens: [String]

    init(numericTokens: [String]) {
        self.numericTokens = numericTokens
    }

    func analyzePrecision() -> [String: Int] {
        var precision: [String: Int] = [:]
        for token in numericTokens {
            if token.contains(".") {
                precision[token] = token.split(separator: ".").last?.count ?? 0
            }
        }
        return precision
    }
}

func main() {
    let text = "The quick brown fox jumps over the lazy dog 123.456 789.10 100.001"
    let processor = TextProcessor(text: text)
    let tokens = processor.tokenize()
    let filteredTokens = processor.filterTokens()
    let parser = NumericParser(tokens: filteredTokens)
    let numericTokens = parser.extractNumeric()
    let analyzer = PrecisionAnalyzer(numericTokens: numericTokens)
    let precisionResults = analyzer.analyzePrecision()
    print(precisionResults)
}

main()