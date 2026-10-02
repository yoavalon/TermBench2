import Foundation

class Tokenizer {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() -> [String] {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let range = NSRange(location: 0, length: text.utf16.count)
        let matches = regex.matches(in: text, options: [], range: range)
        self.tokens = matches.map { String(text[Range($0.range, in: text)!]) }
        return self.tokens
    }
}

class Sequencer {
    var tokens: [String]
    var sequence: [Int]

    init(tokens: [String]) {
        self.tokens = tokens
        self.sequence = []
    }

    func generate_sequence() -> [Int] {
        for token in tokens {
            if let number = Int(token) {
                self.sequence.append(number)
            }
        }
        return self.sequence
    }
}

class Analyzer {
    var sequence: [Int]
    var result: [Int]

    init(sequence: [Int]) {
        self.sequence = sequence
        self.result = []
    }

    func analyze() -> [Int] {
        if !sequence.isEmpty {
            self.result.append(sequence.reduce(0, +))
            self.result.append(sequence.min()!)
            self.result.append(sequence.max()!)
            self.result.append(sequence.count)
        }
        return self.result
    }
}

func main() {
    let text = "The quick brown fox jumps over 13 lazy dogs and 7 cats."
    let tokenizer = Tokenizer(text: text)
    let tokens = tokenizer.tokenize()
    let sequencer = Sequencer(tokens: tokens)
    let sequence = sequencer.generate_sequence()
    let analyzer = Analyzer(sequence: sequence)
    let result = analyzer.analyze()
    print(result)
}

main()