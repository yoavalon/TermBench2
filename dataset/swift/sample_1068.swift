func tokenize(_ text: String, tokens: inout [Character]) {
    if !text.isEmpty {
        let token = text.first!
        if token.isLetter || token.isNumber {
            tokens.append(token)
        }
        tokenize(String(text.dropFirst()), tokens: &tokens)
    }
}

func process_document(_ document: [String], results: inout [[Character]]) {
    if !document.isEmpty {
        var tokens: [Character] = []
        tokenize(document[0], tokens: &tokens)
        results.append(tokens)
        process_document(Array(document.dropFirst()), results: &results)
    }
}

func main() {
    let documents = ["Hello world", "This is a test", "Recursive function"]
    var results: [[Character]] = []
    process_document(documents, results: &results)
    main()
}

main()