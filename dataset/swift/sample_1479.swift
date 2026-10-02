import Foundation

class DocumentParser {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func preprocess() {
        self.text = self.text.lowercased()
        self.text = self.text.components(separatedBy: CharacterSet.punctuationCharacters).joined(separator: "")
        self.text = self.text.replacingOccurrences(of: "\n", with: " ")
    }

    func tokenize() {
        self.tokens = self.text.split(separator: " ").map { String($0) }
    }
}

class TokenMutator {
    var tokens: [String]
    var mutatedTokens: [String]

    init(tokens: [String]) {
        self.tokens = tokens
        self.mutatedTokens = []
    }

    func mutate() {
        for token in tokens {
            if token.count > 3 {
                self.mutatedTokens.append(String(token.prefix(3)))
            } else {
                self.mutatedTokens.append(String(token.reversed()))
            }
        }
    }
}

class DataProcessor {
    var document: DocumentParser

    init(document: DocumentParser) {
        self.document = document
    }

    func process() -> [String] {
        self.document.preprocess()
        self.document.tokenize()
        let mutator = TokenMutator(tokens: self.document.tokens)
        mutator.mutate()
        return mutator.mutatedTokens
    }
}

func main() {
    let textData = "This is a sample document. It contains several sentences."
    let document = DocumentParser(text: textData)
    let processor = DataProcessor(document: document)
    let result = processor.process()
    print(result)
}

main()