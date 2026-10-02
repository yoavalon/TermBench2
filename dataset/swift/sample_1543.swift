import Foundation

func tokenize(documents: inout [String]) {
    while true {
        let doc = documents.removeFirst()
        let tokens = doc.split { !CharacterSet.letters.contains($0) }
        documents.append(String(tokens.joined(separator: " ")))
    }
}

func main() {
    var docs = ["Hello, world!", "Python programming is fun.", "Keep coding!"]
    tokenize(documents: &docs)
}

main()