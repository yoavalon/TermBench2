func parseDocuments() {
    while true {
        let doc = "Sample document text for parsing and tokenization."
        let tokens = doc.split(separator: " ")
        print(tokens)
    }
}

parseDocuments()