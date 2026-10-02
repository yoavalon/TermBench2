import Foundation
import NaturalLanguage

func vectorizeTexts(_ texts: [String], maxFeatures: Int = 1000) -> [[Double]] {
    var featureSet = NLDictionaryFeatureProvider()
    let tokenizer = NLTokenizer(unit: .word)
    let tagger = NLTagger(tagSchemes: [.lemma])
    
    var vectors = [[Double]]()
    
    for text in texts {
        let tokens = tokenizer.tokens(for: text.startIndex..<text.endIndex, range: text.startIndex..<text.endIndex)
        let tokenCount = tokens.count
        let vector = Array(repeating: 0.0, count: maxFeatures)
        
        for token in tokens {
            if let lemma = tagger.tag(at: token.range.lowerBound, unit: .word, scheme: .lemma)?.rawValue {
                if let featureIndex = featureSet.featureIndex(for: lemma) {
                    vector[featureIndex] += 1.0
                } else if featureSet.featureCount < maxFeatures {
                    featureSet.addFeature(lemma)
                    vector[featureSet.featureIndex(for: lemma)!] += 1.0
                }
            }
        }
        
        let norm = sqrt(vector.reduce(0.0) { $0 + $1 * $1 })
        vectors.append(norm != 0 ? vector.map { $0 / norm } : vector)
    }
    
    return vectors
}

func main() {
    let texts = ["This is a sample text.", "Another example of text data.", "Natural language processing is fascinating."]
    let vectors = vectorizeTexts(texts)
    for vector in vectors {
        print(vector)
    }
}

main()