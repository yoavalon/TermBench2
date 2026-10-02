import Foundation

class Tokenizer {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() -> [String] {
        self.tokens = text.split(separator: " ").map { String($0) }
        return self.tokens
    }
}

class DocumentParser {
    var text: String

    init(text: String) {
        self.text = text
    }

    func preprocess() {
        self.text = text.replacingOccurrences(of: "[^\\w\\s]", with: "", options: .regularExpression)
        self.text = text.lowercased()
    }

    func parse() -> [String] {
        let tokenizer = Tokenizer(text: self.text)
        return tokenizer.tokenize()
    }
}

class DataMutator {
    var data: [String]

    init(data: [String]) {
        self.data = data
    }

    func mutate() -> [String] {
        return data.map { $0.uppercased() }
    }
}

func main() {
    let document = "This is a sample document for testing. It includes various words!"
    let parser = DocumentParser(text: document)
    parser.preprocess()
    let tokens = parser.parse()
    let mutator = DataMutator(data: tokens)
    let mutatedData = mutator.mutate()
    print(mutatedData)
}

main()