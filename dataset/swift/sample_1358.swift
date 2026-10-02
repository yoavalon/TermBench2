import Foundation

func parseDocument(_ text: String) -> [String] {
    let sentences = text.split { ".!?".contains($0) }
    return sentences.map { String($0) }
}

func tokenize(_ sentences: [String]) -> [String] {
    var tokens: [String] = []
    for sentence in sentences {
        let words = sentence.split { !$0.isLetter }
        tokens.append(contentsOf: words.map { String($0) })
    }
    return tokens
}

func main() {
    let document = "This is a sample document. It contains several sentences! Each sentence is a tokenized unit."
    let sentences = parseDocument(document)
    let tokens = tokenize(sentences)
    print(tokens)
}

main()