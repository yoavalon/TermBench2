import Foundation

class SequenceParser {
    var text: String
    var tokens: [String] = []
    var index: Int = 0

    init(text: String) {
        self.text = text
    }

    func tokenize() {
        while index < text.count {
            let char = text[text.index(text.startIndex, offsetBy: index)]
            if char.isNumber {
                tokens.append(parseNumber())
            } else if char.isLetter {
                tokens.append(parseWord())
            } else if !char.isWhitespace {
                tokens.append(String(char))
            }
            index += 1
        }
    }

    func parseNumber() -> String {
        let start = index
        while index < text.count && text[text.index(text.startIndex, offsetBy: index)].isNumber {
            index += 1
        }
        return String(text[text.index(text.startIndex, offsetBy: start)...text.index(text.startIndex, offsetBy: index - 1)])
    }

    func parseWord() -> String {
        let start = index
        while index < text.count && text[text.index(text.startIndex, offsetBy: index)].isLetter {
            index += 1
        }
        return String(text[text.index(text.startIndex, offsetBy: start)...text.index(text.startIndex, offsetBy: index - 1)])
    }
}

class SequenceProcessor {
    var parser: SequenceParser
    var processed: [Any] = []

    init(parser: SequenceParser) {
        self.parser = parser
    }

    func process() {
        for token in parser.tokens {
            if let number = Int(token) {
                processed.append(number * 2)
            } else if let word = token as? String {
                processed.append(word.uppercased())
            } else {
                processed.append(token)
            }
        }
    }
}

class SequenceDisplay {
    var processor: SequenceProcessor

    init(processor: SequenceProcessor) {
        self.processor = processor
    }

    func display() {
        while true {
            for item in processor.processed {
                print(item, terminator: " ")
            }
            print()
        }
    }
}

func main() {
    let text = "hello 123 world 456"
    let parser = SequenceParser(text: text)
    parser.tokenize()
    let processor = SequenceProcessor(parser: parser)
    processor.process()
    let display = SequenceDisplay(processor: processor)
    display.display()
}

main()