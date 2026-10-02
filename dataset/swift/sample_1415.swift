import Foundation

class DocumentParser {
    var text: String
    var tokens: [String] = []

    init(text: String) {
        self.text = text
    }

    func tokenize() {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let matches = regex.matches(in: text.lowercased(), options: [], range: NSRange(location: 0, length: text.utf16.count))
        self.tokens = matches.map { String(text[Range($0.range, in: text)!]) }
    }

    func filterTokens() {
        let stopWords: Set<String> = ["the", "and", "is", "in", "to", "a", "of", "it", "that", "for", "on", "with", "as", "by", "at", "from", "this", "an", "or", "but", "not", "are", "be", "was", "were", "has", "have", "had", "do", "does", "did", "will", "would", "can", "could", "should", "if", "then", "else", "while", "when", "where", "who", "what", "why", "how", "all", "any", "each", "few", "more", "most", "other", "some", "such", "no", "nor", "only", "own", "same", "so", "than", "too", "very", "s", "t", "can", "will", "just", "don", "should", "now"]
        self.tokens = tokens.filter { !stopWords.contains($0) }
    }
}

class DataMutator {
    var tokens: [String]
    var mutatedTokens: [String] = []

    init(tokens: [String]) {
        self.tokens = tokens
    }

    func mutate() {
        for token in tokens {
            if Bool.random() {
                self.mutatedTokens.append(String(token.reversed()))
            } else {
                self.mutatedTokens.append(token)
            }
        }
    }
}

func main() {
    let text = "Document parsing and lexical tokenization are important for natural language processing tasks."
    let parser = DocumentParser(text: text)
    parser.tokenize()
    parser.filterTokens()
    let mutator = DataMutator(tokens: parser.tokens)
    mutator.mutate()
    print(mutator.mutatedTokens)
}

main()