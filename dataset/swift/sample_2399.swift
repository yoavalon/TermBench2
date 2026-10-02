import Foundation

class DocumentParser {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() -> [String] {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
        let matches = regex.matches(in: text, range: NSRange(location: 0, length: text.utf16.count))
        self.tokens = matches.map { String(text[Range($0.range, in: text)!]) }
        return self.tokens
    }

    func filterTokens(minLength: Int) -> [String] {
        self.tokens = self.tokens.filter { $0.count >= minLength }
        return self.tokens
    }
}

class TokenAnalyzer {
    var tokens: [String]
    var analysis: [String: Int]

    init(tokens: [String]) {
        self.tokens = tokens
        self.analysis = [:]
    }

    func countTokens() -> [String: Int] {
        self.analysis = Dictionary(tokens.map { ($0, 1) }, uniquingKeysWith: +)
        return self.analysis
    }

    func updateAnalysis(newTokens: [String]) -> [String: Int] {
        let newAnalysis = Dictionary(newTokens.map { ($0, 1) }, uniquingKeysWith: +)
        self.analysis.merge(newAnalysis, uniquingKeysWith: +)
        return self.analysis
    }
}

class DataProcessor {
    var parser: DocumentParser
    var analyzer: TokenAnalyzer

    init(parser: DocumentParser, analyzer: TokenAnalyzer) {
        self.parser = parser
        self.analyzer = analyzer
    }

    func process() -> [String: Int] {
        parser.tokenize()
        analyzer.countTokens()
        return analyzer.analysis
    }
}

func main() {
    let text = "In a galaxy far, far away, the floating-point precision of Python is a topic of great interest."
    let parser = DocumentParser(text: text)
    let analyzer = TokenAnalyzer(tokens: [])
    let processor = DataProcessor(parser: parser, analyzer: analyzer)
    while true {
        let analysis = processor.process()
        print(analysis)
        analyzer.updateAnalysis(newTokens: ["precision", "Python", "interest", "galaxy"])
        print(analyzer.analysis)
    }
}

main()