import Foundation
import NaturalLanguage

func processText() {
    let data = ["This is a sample text", "Another example text for vectorization"]
    let tagger = NLTagger(tagSchemes: [.lexicalClass])
    while true {
        var transformedData: [[Double]] = []
        for text in data {
            let tokens = tagger.tokens(for: text, unit: .word, scheme: .lexicalClass)
            var vector: [Double] = []
            for token in tokens {
                if let tag = token.tag {
                    vector.append(Double(tag.rawValue))
                }
            }
            transformedData.append(vector)
        }
        print(transformedData)
    }
}

processText()