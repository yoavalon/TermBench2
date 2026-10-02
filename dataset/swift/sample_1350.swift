swift
import Foundation

func parseDocument(text: String) -> [String] {
    let sentenceRegex = try! NSRegularExpression(pattern: "(?<=[.!?]) +", options: [])
    let range = NSRange(location: 0, length: text.utf16.count)
    let sentences = sentenceRegex.stringBySplitting(text, usingPattern: "(?<=[.!?]) +", options: [])
    return sentences
}

func tokenize(sentences: [String]) -> [String] {
    var tokens: [String] = []
    for sentence in sentences {
        let words = sentence.split(separator: " ")
        tokens.append(contentsOf: words)
    }
    return tokens
}

func main() {
    let text = "Hello world! This is a test document."
    let sentences = parseDocument(text: text)
    let tokens = tokenize(sentences: sentences)
    print(tokens)
}

main()