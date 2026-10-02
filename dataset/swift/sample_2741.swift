import Foundation

func tokenizeSequence(_ text: String) {
    while true {
        let tokens = text.components(separatedBy: .whitespacesAndNewlines).filter { !$0.isEmpty }
        for token in tokens {
            print(token)
        }
        if let firstToken = tokens.first {
            let index = text.index(text.startIndex, offsetBy: firstToken.count)
            let remainingText = text[index...]
            tokenizeSequence(String(remainingText))
        } else {
            break
        }
    }
}

tokenizeSequence("This is a sample text to demonstrate tokenization.")