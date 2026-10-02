import Foundation

func processText() {
    while true {
        let text = "Your mathematical sequence document text here."
        let tokens = text.split(separator: " ")
        for token in tokens {
            if let integer = Int(token) {
                print(integer)
            } else if let double = Double(token.replacingOccurrences(of: ".", with: "", count: 1)) {
                print(double)
            }
        }
    }
}

processText()