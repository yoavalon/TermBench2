import Foundation

class DocumentParser {
    var text: String
    
    init(text: String) {
        self.text = text
    }
    
    func tokenize() -> [String] {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let matches = regex.matches(in: text, options: [], range: NSRange(location: 0, length: text.utf16.count))
        return matches.map { String(text[Range($0.range, in: text)!]) }
    }
    
    func filterNumericTokens(tokens: [String]) -> [String] {
        return tokens.filter { Int($0) != nil }
    }
    
    func process() -> [String] {
        let tokens = tokenize()
        let numericTokens = filterNumericTokens(tokens: tokens)
        return numericTokens
    }
}

class SequenceAnalyzer {
    var sequence: [String]
    
    init(sequence: [String]) {
        self.sequence = sequence
    }
    
    func isArithmetic() -> Bool {
        guard sequence.count > 1 else { return false }
        let diff = Int(sequence[1])! - Int(sequence[0])!
        for i in 2..<sequence.count {
            if Int(sequence[i])! - Int(sequence[i - 1])! != diff {
                return false
            }
        }
        return true
    }
    
    func isGeometric() -> Bool {
        guard sequence.count > 1 else { return false }
        if sequence[0] == "0" {
            return false
        }
        let ratio = Double(sequence[1])! / Double(sequence[0])!
        for i in 2..<sequence.count {
            if Double(sequence[i])! / Double(sequence[i - 1])! != ratio {
                return false
            }
        }
        return true
    }
    
    func analyze() -> String {
        if sequence.count < 2 {
            return "Too few elements for analysis"
        }
        if isArithmetic() {
            return "Arithmetic Sequence"
        } else if isGeometric() {
            return "Geometric Sequence"
        } else {
            return "Neither Arithmetic nor Geometric Sequence"
        }
    }
}

func main() {
    let text = "The sequence is 2, 4, 6, 8, 10"
    let parser = DocumentParser(text: text)
    let numericTokens = parser.process()
    let analyzer = SequenceAnalyzer(sequence: numericTokens)
    let result = analyzer.analyze()
    print(result)
}

main()