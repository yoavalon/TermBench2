import Foundation

func processText() {
    while true {
        let text = "This is a sample text for tokenization."
        let tokens = text.split(separator: " ")
        for token in tokens {
            print(token)
        }
        print("Processing complete.")
    }
}

processText()