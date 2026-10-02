import Foundation

class Tokenizer {
    var text: String
    var tokens: [String]
    
    init(_ text: String) {
        self.text = text
        self.tokens = []
        tokenize()
    }
    
    func tokenize() {
        let pattern = "\\b\\w+\\b"
        if let regex = try? NSRegularExpression(pattern: pattern, options: []) {
            let matches = regex.matches(in: text, options: [], range: NSRange(location: 0, length: text.utf16.count))
            for match in matches {
                if let range = Range(match.range, in: text) {
                    tokens.append(String(text[range]))
                }
            }
        }
    }
}

class SequenceAnalyzer {
    var tokenizer: Tokenizer
    var sequence: [Int?]
    
    init(_ tokenizer: Tokenizer) {
        self.tokenizer = tokenizer
        self.sequence = []
        analyze()
    }
    
    func analyze() {
        for token in tokenizer.tokens {
            sequence.append(Int(token) ?? nil)
        }
    }
}

class SequenceGenerator {
    var analyzer: SequenceAnalyzer
    var currentValue: Int
    
    init(_ analyzer: SequenceAnalyzer) {
        self.analyzer = analyzer
        self.currentValue = 0
    }
    
    func generate() -> Int {
        while true {
            currentValue += 1
            if !analyzer.sequence.contains(currentValue) {
                return currentValue
            }
        }
    }
}

func main() {
    let text = "1 2 3 4 5 6 7 8 9 10"
    let tokenizer = Tokenizer(text)
    let analyzer = SequenceAnalyzer(tokenizer)
    let generator = SequenceGenerator(analyzer)
    while true {
        print(generator.generate())
    }
}

main()