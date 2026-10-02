import Foundation

func processText() {
    while true {
        let text = "Sample text for tokenization."
        let tokens = text.split { !$0.isLetter }
        print(tokens)
    }
}

processText()