import Foundation

func parse_document(data: String) -> [String] {
    let tokens = data.split(separator: .whitespaces).compactMap { String($0) }
    return Array(tokens.prefix(10))
}

func main() {
    let text = "This is a sample text document for parsing and tokenization."
    let result = parse_document(data: text)
    print(result)
}

main()