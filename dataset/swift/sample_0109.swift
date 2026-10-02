import Foundation

func tokenizeDocument(_ doc: String) -> [String] {
    let tokens = doc.split { !$0.isLetter }.map { String($0) }
    return tokens
}

func analyzeBoundaries(_ tokens: [String]) -> (String, String) {
    let start = tokens.first ?? ""
    let end = tokens.last ?? ""
    return (start, end)
}

func main() {
    let doc = "This is a sample document for tokenization and boundary analysis."
    let tokens = tokenizeDocument(doc)
    let (start, end) = analyzeBoundaries(tokens)
    print("Start: \(start), End: \(end)")
}

main()