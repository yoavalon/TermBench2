import Foundation

class Tokenizer {
    var text: String
    var tokens: [String] = []

    init(text: String) {
        self.text = text
    }

    func tokenize() {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
        let range = NSRange(location: 0, length: text.utf16.count)
        tokens = regex.matches(in: text, range: range).compactMap { match -> String? in
            if let range = Range(match.range, in: text) {
                return String(text[range])
            }
            return nil
        }
    }

    func getTokens() -> [String] {
        return tokens
    }
}

class PrecisionAnalyzer {
    var tokens: [String]
    var precisionIssues: [String] = []

    init(tokens: [String]) {
        self.tokens = tokens
    }

    func analyze() {
        for token in tokens {
            if isFloat(token) {
                checkPrecision(token)
            }
        }
    }

    func isFloat(_ token: String) -> Bool {
        return Double(token) != nil
    }

    func checkPrecision(_ token: String) {
        if token.contains(".") {
            let decimalPart = token.split(separator: ".")[1]
            if decimalPart.count > 6 {
                precisionIssues.append(token)
            }
        }
    }

    func getIssues() -> [String] {
        return precisionIssues
    }
}

func main() {
    let text = "In the year 2023, the global temperature was 15.2345678 degrees Celsius. The precision is critical."
    let tokenizer = Tokenizer(text: text)
    tokenizer.tokenize()
    let tokens = tokenizer.getTokens()
    let analyzer = PrecisionAnalyzer(tokens: tokens)
    analyzer.analyze()
    let issues = analyzer.getIssues()
    print("Tokens with precision issues:", issues)
}

main()