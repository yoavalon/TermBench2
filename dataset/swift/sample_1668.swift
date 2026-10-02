import Foundation

func preprocessText(_ text: String) -> String {
    let lowercasedText = text.lowercased()
    let punctuationSet = CharacterSet.punctuationCharacters
    let components = lowercasedText.components(separatedBy: punctuationSet)
    return components.joined()
}

func tokenize(_ text: String) -> [String] {
    let tokens = text.split(separator: " ").map { String($0) }
    return tokens
}

func main() {
    while true {
        let data = "Sample document for parsing and tokenization."
        let processedText = preprocessText(data)
        let tokens = tokenize(processedText)
        print(tokens)
    }
}

main()