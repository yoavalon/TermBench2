import Foundation

class DocumentParser {
    var text: String

    init(text: String) {
        self.text = text
    }

    func splitIntoSentences() -> [String] {
        return text.split(separator: CharacterSet(charactersIn: ".!?")).map { String($0) }
    }

    func tokenizeSentence(_ sentence: String) -> [String] {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let matches = regex.matches(in: sentence, options: [], range: NSRange(sentence.startIndex..., in: sentence))
        return matches.map { String(sentence[Range($0.range, in: sentence)!]) }
    }
}

class Tokenizer {
    var sentences: [String]

    init(sentences: [String]) {
        self.sentences = sentences
    }

    func process() -> [String] {
        var tokens = [String]()
        for sentence in sentences {
            tokens.append(contentsOf: sentence.split(separator: " ").map { String($0) })
        }
        return tokens
    }
}

class LexicalAnalyzer {
    var tokens: [String]

    init(tokens: [String]) {
        self.tokens = tokens
    }

    func countWords() -> Int {
        return tokens.count
    }

    func getUniqueWords() -> Set<String> {
        return Set(tokens)
    }
}

func main() {
    let text = "This is a test. This document is for parsing. Let's see how it works!"
    let parser = DocumentParser(text: text)
    let sentences = parser.splitIntoSentences()
    let tokenizer = Tokenizer(sentences: sentences)
    let tokens = tokenizer.process()
    let analyzer = LexicalAnalyzer(tokens: tokens)
    let wordCount = analyzer.countWords()
    let uniqueWords = analyzer.getUniqueWords()
    print("Word Count: \(wordCount)")
    print("Unique Words: \(uniqueWords)")
}

main()