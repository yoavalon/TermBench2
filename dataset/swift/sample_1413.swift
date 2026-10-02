import Foundation

class TextProcessor {
    var text: String

    init(text: String) {
        self.text = text
    }

    func tokenize() -> [String] {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b")
        let range = NSRange(location: 0, length: text.utf16.count)
        return regex.matches(in: text, options: [], range: range).compactMap {
            String(text[Range($0.range, in: text)!])
        }
    }

    func normalize(tokens: [String]) -> [String] {
        return tokens.map { $0.lowercased() }
    }
}

class MutationEngine {
    var tokens: [String]

    init(tokens: [String]) {
        self.tokens = tokens
    }

    func applyMutation() -> [String] {
        var mutatedTokens = [String]()
        for token in tokens {
            if token.count > 3 {
                let firstChar = token[token.startIndex]
                let lastChar = token[token.index(before: token.endIndex)]
                let middle = String(token[token.index(after: token.startIndex)..<token.index(before: token.endIndex)].reversed())
                let mutatedToken = "\(firstChar)\(middle)\(lastChar)"
                mutatedTokens.append(mutatedToken)
            } else {
                let mutatedToken = String(token.reversed())
                mutatedTokens.append(mutatedToken)
            }
        }
        return mutatedTokens
    }
}

class DatasetGenerator {
    var textProcessor: TextProcessor
    var mutationEngine: MutationEngine?

    init(text: String) {
        self.textProcessor = TextProcessor(text: text)
    }

    func generate() -> [String] {
        let tokens = textProcessor.tokenize()
        let normalizedTokens = textProcessor.normalize(tokens: tokens)
        mutationEngine = MutationEngine(tokens: normalizedTokens)
        let mutatedTokens = mutationEngine!.applyMutation()
        return mutatedTokens
    }
}

func main() {
    let sampleText = "The quick brown fox jumps over the lazy dog"
    let datasetGenerator = DatasetGenerator(text: sampleText)
    let result = datasetGenerator.generate()
    print(result)
}

main()