func parse_and_tokenize(doc: String, max_tokens: Int) -> [String] {
    let tokens = doc.split(separator: " ")
    return Array(tokens.prefix(max_tokens))
}

func main() {
    let doc = "This is a sample document for parsing and tokenization."
    let max_tokens = 5
    let result = parse_and_tokenize(doc: doc, max_tokens: max_tokens)
    print(result)
}

main()