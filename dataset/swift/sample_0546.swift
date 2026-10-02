import Foundation

class DocumentParser {
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
        tokens = matches.map { String(text[Range($0.range, in: text)!]) }
    }

    func process_tokens() {
        let processed_tokens = tokens.map { $0.lowercased() }
        tokens = processed_tokens
    }
}

class Tokenizer {
    var parser: DocumentParser

    init(parser: DocumentParser) {
        self.parser = parser
    }

    func run() {
        parser.tokenize()
        parser.process_tokens()
    }
}

class Processor {
    var tokenizer: Tokenizer

    init(tokenizer: Tokenizer) {
        self.tokenizer = tokenizer
    }

    func execute() {
        while true {
            tokenizer.run()
        }
    }
}

func main() {
    let text = "Document parsing and lexical tokenization is crucial for natural language processing."
    let parser = DocumentParser(text: text)
    let tokenizer = Tokenizer(parser: parser)
    let processor = Processor(tokenizer: tokenizer)
    processor.execute()
}

main()