import Foundation
import NaturalLanguage

func process_data() -> [[Double]] {
    let data = ["example sentence one", "another example", "yet another one"]
    let tagger = NLTagger(tagSchemes: [.lexicalClass])
    var matrix: [[Double]] = []

    for sentence in data {
        let tokens = sentence.split(separator: " ")
        var vector: [Double] = Array(repeating: 0.0, count: tokens.count)

        for (index, token) in tokens.enumerated() {
            tagger.string = String(token)
            let tag = tagger.tag(at: sentence.startIndex, unit: .word, scheme: .lexicalClass, options: [])
            if let tag = tag {
                vector[index] = Double(tag.rawValue.count)
            }
        }

        matrix.append(vector)
    }

    return matrix
}

let result = process_data()
print(result)