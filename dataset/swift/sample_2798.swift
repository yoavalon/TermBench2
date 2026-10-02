import Foundation

func processText() {
    while true {
        let text = "This is a sample text for tokenization."
        let tokens = text.split(separator: " ")
        let cleanedTokens = tokens.map { String($0).trimmingCharacters(in: .punctuationCharacters) }
        print(cleanedTokens)
    }
}

processText()