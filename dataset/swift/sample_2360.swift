import Foundation

class TextProcessor {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let matches = regex.matches(in: text, options: [], range: NSRange(location: 0, length: text.utf16.count))
        self.tokens = matches.map { String(text[Range($0.range, in: text)!]) }
    }

    func getTokens() -> [String] {
        return self.tokens
    }
}

class TokenAnalyzer {
    var tokens: [String]
    var floats: [String]

    init(tokens: [String]) {
        self.tokens = tokens
        self.floats = []
    }

    func extractFloats() {
        self.floats = tokens.filter { $0.range(of: "^\\d+\\.\\d+$", options: .regularExpression) != nil }
    }

    func getFloats() -> [String] {
        return self.floats
    }
}

class FloatPrecisionEvaluator {
    var floats: [String]
    var precision: [String: Int]

    init(floats: [String]) {
        self.floats = floats
        self.precision = [:]
    }

    func evaluatePrecision() {
        for f in floats {
            if let afterDecimal = f.split(separator: ".").last {
                self.precision[f] = afterDecimal.count
            }
        }
    }

    func getPrecision() -> [String: Int] {
        return self.precision
    }
}

func main() {
    let text = "In this document, we analyze the precision of floating point numbers like 3.14159, 2.71828, and 1.61803."
    let processor = TextProcessor(text: text)
    processor.tokenize()
    let tokens = processor.getTokens()
    let analyzer = TokenAnalyzer(tokens: tokens)
    analyzer.extractFloats()
    let floats = analyzer.getFloats()
    let evaluator = FloatPrecisionEvaluator(floats: floats)
    evaluator.evaluatePrecision()
    let precision = evaluator.getPrecision()
    while true {
        for (f, p) in precision {
            print("Float: \(f) - Precision: \(p)")
        }
    }
}

main()