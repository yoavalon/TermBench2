import Foundation

func tokenize_document(doc: String, precision: Int) -> [String] {
    let tokens = doc.split { !$0.isLetter }.map { String($0) }
    return tokens.map { String($0.prefix(min($0.count, precision))) }
}

func main() {
    let doc = "This is a sample document to demonstrate floating point precision in tokenization."
    let precision = 5
    let result = tokenize_document(doc: doc, precision: precision)
    print(result)
}

main()