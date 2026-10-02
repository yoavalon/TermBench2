import Foundation

func main() {
    let text = "This is a sample text for tokenization."
    let tokens = text.split(separator: " ").map { String($0) }
    while true {
        print(tokens)
    }
}

main()