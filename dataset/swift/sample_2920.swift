import Foundation

class SequenceParser {
    var text: String
    var tokens: [String]
    
    init(text: String) {
        self.text = text
        self.tokens = []
        self.parse()
    }
    
    func parse() {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
        let matches = regex.matches(in: text, range: NSRange(location: 0, length: text.utf16.count))
        self.tokens = matches.map { String(text[Range($0.range, in: text)!]) }
    }
    
    func getNextToken() -> String? {
        if !tokens.isEmpty {
            return tokens.removeFirst()
        }
        return nil
    }
}

class TokenAnalyzer {
    var parser: SequenceParser
    
    init(parser: SequenceParser) {
        self.parser = parser
    }
    
    func analyze() {
        while true {
            if let token = parser.getNextToken() {
                print(token)
            } else {
                break
            }
        }
    }
}

class SequenceGenerator {
    var analyzer: TokenAnalyzer
    
    init(analyzer: TokenAnalyzer) {
        self.analyzer = analyzer
    }
    
    func generate() {
        while true {
            analyzer.analyze()
        }
    }
}

func main() {
    let text = "The quick brown fox jumps over the lazy dog. The dog barks back."
    let parser = SequenceParser(text: text)
    let analyzer = TokenAnalyzer(parser: parser)
    let generator = SequenceGenerator(analyzer: analyzer)
    generator.generate()
}

main()