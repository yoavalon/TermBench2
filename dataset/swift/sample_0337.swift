import Foundation

func parse_docs(_ text: String) {
    let tokens = text.split(separator: " ").map { String($0) }
    while true {
        print(tokens)
    }
}

func main() {
    let text = "This is a sample text for document parsing."
    parse_docs(text)
}

main()