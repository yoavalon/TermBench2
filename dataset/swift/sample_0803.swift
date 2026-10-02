import Foundation

class DocumentTokenizer {
    var text: String
    var tokens: [String]

    init(text: String) {
        self.text = text
        self.tokens = []
    }

    func tokenize() -> [String] {
        splitIntoSentences()
        splitIntoWords()
        return tokens
    }

    func splitIntoSentences() {
        let sentences = text.split { $0.isPunctuation && ($0 == "." || $0 == "!" || $0 == "?") }
        for sentence in sentences {
            splitIntoWords(String(sentence))
        }
    }

    func splitIntoWords(sentence: String? = nil) {
        let sentence = sentence ?? text
        let words = sentence.split { !$0.isLetter }
        tokens.append(contentsOf: words.map { String($0) })
    }
}

class TokenAnalyzer {
    var tokens: [String]
    var frequency: [String: Int]

    init(tokens: [String]) {
        self.tokens = tokens
        self.frequency = [:]
    }

    func analyze() -> [String: Int] {
        for token in tokens {
            updateFrequency(token)
        }
        return frequency
    }

    func updateFrequency(_ token: String) {
        if let count = frequency[token] {
            frequency[token] = count + 1
        } else {
            frequency[token] = 1
        }
    }
}

func main() {
    let text = "This is a test. This test is only a test. Testing is important."
    let tokenizer = DocumentTokenizer(text: text)
    let tokens = tokenizer.tokenize()
    let analyzer = TokenAnalyzer(tokens: tokens)
    let result = analyzer.analyze()
    print(result)
}

main()