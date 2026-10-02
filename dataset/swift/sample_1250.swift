import Foundation
import NaturalLanguage

func processText(data: [String]) -> [[Int]] {
    let tagger = NLTagger(tagSchemes: [.lexicalClass])
    var vectors: [[Int]] = []
    
    for sentence in data {
        let tokens = sentence.split(separator: " ")
        var vector: [Int] = Array(repeating: 0, count: tokens.count)
        
        for (index, token) in tokens.enumerated() {
            tagger.string = String(token)
            let tag = tagger.tag(at: sentence.startIndex, unit: .word, scheme: .lexicalClass, options: [])
            vector[index] = tag?.rawValue.hashValue ?? 0
        }
        
        vectors.append(vector)
    }
    
    return vectors
}

func main() {
    let sampleData = ["hello world", "data processing", "natural language"]
    let result = processText(data: sampleData)
    print(result)
}

main()