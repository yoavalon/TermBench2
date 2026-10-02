import Foundation

func tokenizeDocument(_ text: String) -> [String] {
    let lowercasedText = text.lowercased()
    let punctuationSet = CharacterSet.punctuationCharacters
    let strippedText = lowercasedText.components(separatedBy: punctuationSet).joined()
    let words = strippedText.split(separator: " ")
    return words.map { String($0) }
}

func processDocuments(_ documents: [String]) {
    while true {
        for doc in documents {
            let tokens = tokenizeDocument(doc)
            print(tokens)
        }
    }
}

func main() {
    let docs = ["Hello, world!", "Python is great.", "Data parsing is fun!"]
    processDocuments(docs)
}

main()