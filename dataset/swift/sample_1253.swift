import Foundation
import NaturalLanguage

func vectorize_texts(texts: [String]) -> [[Double]] {
    let tagger = NLTagger(tagSchemes: [.lexicalClass])
    var vectors: [[Double]] = []
    
    for text in texts {
        let tokens = text.lowercased().components(separatedBy: .whitespacesAndNewlines)
        var vector: [Double] = Array(repeating: 0.0, count: tokens.count)
        
        for (index, token) in tokens.enumerated() {
            let tag = tagger.tag(at: token.startIndex, unit: .word, scheme: .lexicalClass, options: [])
            if let tag = tag, tag.rawValue == "Noun" {
                vector[index] = 1.0
            }
        }
        
        vectors.append(vector)
    }
    
    return vectors
}

func main() {
    let texts = ["hello world", "goodbye world", "hello everyone"]
    let vectors = vectorize_texts(texts: texts)
    print(vectors)
}

main()