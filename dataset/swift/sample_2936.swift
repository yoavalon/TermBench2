import Foundation

class SequenceParser {
    var data = ""
    var tokens: [String] = []

    init() {}

    func parse(_ text: String) {
        data = text
        tokenize()
    }

    func tokenize() {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let matches = regex.matches(in: data, options: [], range: NSRange(location: 0, length: data.utf16.count))
        tokens = matches.map { String(data[Range($0.range, in: data)!]) }
    }
}

class SequenceAnalyzer {
    var sequence: [Int] = []

    init() {}

    func analyze(_ tokens: [String]) {
        for token in tokens {
            if let num = Int(token) {
                sequence.append(num)
            }
        }
    }
}

class SequenceGenerator {
    var current = 0

    init() {}

    func generate() -> AnyIterator<Int> {
        return AnyIterator {
            defer { self.current += 1 }
            return self.current
        }
    }
}

func main() {
    let parser = SequenceParser()
    let analyzer = SequenceAnalyzer()
    let generator = SequenceGenerator()
    let text = "The quick brown fox jumps over the lazy dog 12345 67890"
    parser.parse(text)
    analyzer.analyze(parser.tokens)
    for num in generator.generate() {
        if analyzer.sequence.contains(num) {
            print(num)
        }
    }
}

main()