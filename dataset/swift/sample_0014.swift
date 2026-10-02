import Foundation

func main() {
    let text = "This is a sample text for document parsing and lexical tokenization."
    let tokens = text.split(separator: " ").map { String($0) }
    for i in 0..<5 {
        print(tokens[i])
    }
}

main()