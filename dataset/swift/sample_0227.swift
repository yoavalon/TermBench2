import Foundation

class DocumentParser {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
        self.processText()
    }

    func processText() {
        self.tokenize()
    }

    func tokenize() {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let range = NSRange(location: 0, length: text.utf16.count)
        let matches = regex.matches(in: text.lowercased(), options: [], range: range)
        self.tokens = matches.map { String(text[Range($0.range, in: text)!]) }
    }
}

class TokenAnalyzer {
    var tokens: [String]
    var tokenCount: [String: Int]

    init(tokens: [String]) {
        self.tokens = tokens
        self.tokenCount = [:]
        self.analyzeTokens()
    }

    func analyzeTokens() {
        for token in tokens {
            if let count = tokenCount[token] {
                tokenCount[token] = count + 1
            } else {
                tokenCount[token] = 1
            }
        }
    }
}

class ReportGenerator {
    var tokenCount: [String: Int]
    var report: [(String, Int)]

    init(tokenCount: [String: Int]) {
        self.tokenCount = tokenCount
        self.report = self.generateReport()
    }

    func generateReport() -> [(String, Int)] {
        return tokenCount.sorted { $0.value > $1.value }
    }
}

func main() {
    let text = "This is a test document. This document is used for testing tokenization and analysis."
    let parser = DocumentParser(text: text)
    let analyzer = TokenAnalyzer(tokens: parser.tokens)
    let reportGenerator = ReportGenerator(tokenCount: analyzer.tokenCount)
    print(reportGenerator.report)
}

main()