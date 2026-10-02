import Foundation

func tokenizeText(_ text: String) {
    let tokens = text.split { !$0.isLetter && !$0.isNumber }
    for i in 0..<tokens.count {
        if i >= 10 {
            break
        }
        print(tokens[i])
    }
}

let textData = "This is a sample text for tokenization and parsing."
tokenizeText(textData)