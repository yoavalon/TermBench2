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
        let range = NSRange(location: 0, length: text.utf16.count)
        let matches = regex.matches(in: text, options: [], range: range)
        self.tokens = matches.map { String(text[Range($0.range, in: text)!]).lowercased() }
    }
}

class SequenceAnalyzer {
    var tokens: [String]
    var sequences: [String: Int]

    init(tokens: [String]) {
        self.tokens = tokens
        self.sequences = [:]
    }

    func identify_sequences() {
        for i in 0..<(tokens.count - 1) {
            let pair = "\(tokens[i]) \(tokens[i + 1])"
            sequences[pair, default: 0] += 1
        }
    }
}

class ReportGenerator {
    var sequences: [String: Int]

    init(sequences: [String: Int]) {
        self.sequences = sequences
    }

    func generate_report() -> [(String, Int)] {
        return sequences.sorted { $0.value > $1.value }
    }
}

func main() {
    let text = "This is a test text for parsing and tokenization. We will test the text processing and sequence analysis."
    let processor = TextProcessor(text: text)
    processor.tokenize()
    let analyzer = SequenceAnalyzer(tokens: processor.tokens)
    analyzer.identify_sequences()
    let generator = ReportGenerator(sequences: analyzer.sequences)
    let report = generator.generate_report()
    for (sequence, count) in report.prefix(10) {
        print("Sequence: \(sequence), Count: \(count)")
    }
}

main()