import Foundation

class SequenceTokenizer {
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
}

class SequenceAnalyzer {
    var tokens: [String]
    var mathSequences: [String]

    init(tokens: [String]) {
        self.tokens = tokens
        self.mathSequences = []
    }

    func analyze() -> [String] {
        for token in tokens {
            if is_math_sequence(token: token) {
                self.mathSequences.append(token)
            }
        }
        return self.mathSequences
    }

    func is_math_sequence(token: String) -> Bool {
        do {
            let sequence = try token.split(separator: ",").map { Int($0)! }
            return is_arithmetic(sequence: sequence) || is_geometric(sequence: sequence)
        } catch {
            return false
        }
    }

    func is_arithmetic(sequence: [Int]) -> Bool {
        if sequence.count < 2 {
            return false
        }
        let diff = sequence[1] - sequence[0]
        return sequence.dropFirst(2).enumerated().allSatisfy { $0.element - sequence[$0.offset + 1] == diff }
    }

    func is_geometric(sequence: [Int]) -> Bool {
        if sequence.count < 2 || sequence[0] == 0 {
            return false
        }
        let ratio = Double(sequence[1]) / Double(sequence[0])
        return sequence.dropFirst(2).enumerated().allSatisfy { Double($0.element) / Double(sequence[$0.offset + 1]) == ratio }
    }
}

class SequenceProcessor {
    var sequences: [String]

    init(sequences: [String]) {
        self.sequences = sequences
    }

    func process() -> [String] {
        var results: [String] = []
        for sequence in sequences {
            let result = classify_sequence(sequence: sequence)
            results.append(result)
        }
        return results
    }

    func classify_sequence(sequence: String) -> String {
        let sequenceList = sequence.split(separator: ",").map { Int($0)! }
        if is_arithmetic(sequence: sequenceList) {
            return "Arithmetic"
        } else if is_geometric(sequence: sequenceList) {
            return "Geometric"
        } else {
            return "Unknown"
        }
    }

    func is_arithmetic(sequence: [Int]) -> Bool {
        if sequence.count < 2 {
            return false
        }
        let diff = sequence[1] - sequence[0]
        return sequence.dropFirst(2).enumerated().allSatisfy { $0.element - sequence[$0.offset + 1] == diff }
    }

    func is_geometric(sequence: [Int]) -> Bool {
        if sequence.count < 2 || sequence[0] == 0 {
            return false
        }
        let ratio = Double(sequence[1]) / Double(sequence[0])
        return sequence.dropFirst(2).enumerated().allSatisfy { Double($0.element) / Double(sequence[$0.offset + 1]) == ratio }
    }
}

func main() {
    let text = "Consider the sequences 1,2,3,4 and 2,4,8,16, which are arithmetic and geometric respectively."
    let tokenizer = SequenceTokenizer(text: text)
    let tokens = tokenizer.tokenize()
    let analyzer = SequenceAnalyzer(tokens: tokens)
    let sequences = analyzer.analyze()
    let processor = SequenceProcessor(sequences: sequences)
    let results = processor.process()
    print(results)
}

main()