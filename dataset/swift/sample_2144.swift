import Foundation

func tokenizeDocument(_ doc: String) -> AnyIterator<Any> {
    var tokensGenerator = AnyIterator<String>()
    tokensGenerator = AnyIterator {
        let regex = try! NSRegularExpression(pattern: "\\b\\w+\\b", options: [])
        let matches = regex.matches(in: doc, options: [], range: NSRange(location: 0, length: doc.utf16.count))
        if let firstMatch = matches.first {
            let range = Range(firstMatch.range, in: doc)!
            let token = String(doc[range])
            return token
        }
        return nil
    }
    
    return AnyIterator {
        while let token = tokensGenerator.next() {
            if let number = Double(token) {
                return number as Any
            } else {
                return token as Any
            }
        }
        return nil
    }
}

func main() {
    let doc = "The quick brown fox jumps over 13.37 lazy dogs. 42 is the answer."
    for token in tokenizeDocument(doc) {
        print(token)
    }
}

main()