import Foundation
import Accelerate

func preprocess_data(data: [String]) -> [[Double]] {
    let corpus = data.joined(separator: "\n")
    let options: [String: Any] = [
        "tokenizationOptions": NSLinguisticTagger.Options.omitWhitespace.rawValue,
        "tagSchemes": [NSLinguisticTagScheme.lexicalClass.rawValue],
        "language": NSLocale.preferredLanguages.first ?? "en"
    ]
    
    let tagger = NSLinguisticTagger(tagSchemes: options["tagSchemes"] as! [String], options: options["tokenizationOptions"] as! Int)
    tagger.string = corpus
    
    var tfidfMatrix: [[Double]] = []
    for sentence in data {
        var termFrequencyDict: [String: Double] = [:]
        let sentenceLength = Double(sentence.split(separator: " ").count)
        
        tagger.enumerateTags(in: sentence.startIndex..<sentence.endIndex, unit: .word, scheme: .lexicalClass, options: []) { tag, tokenRange in
            if let tag = tag {
                let term = String(sentence[tokenRange])
                termFrequencyDict[term, default: 0.0] += 1.0
            }
        }
        
        for term in termFrequencyDict.keys {
            termFrequencyDict[term] = termFrequencyDict[term]! / sentenceLength
        }
        
        let sentenceVector: [Double] = data.map { sentence in
            let termFrequency = termFrequencyDict[sentence, default: 0.0]
            let inverseDocumentFrequency = Double(data.filter { $0.contains(term) }.count) == 0 ? 0.0 : log(Double(data.count) / Double(data.filter { $0.contains(term) }.count))
            return termFrequency * inverseDocumentFrequency
        }
        
        tfidfMatrix.append(sentenceVector)
    }
    
    return tfidfMatrix
}

func analyze_vectors(vectors: [[Double]]) -> ([Double], [Double]) {
    var meanVector: [Double] = []
    var varianceVector: [Double] = []
    
    for i in 0..<vectors[0].count {
        let mean = vectors.map { $0[i] }.reduce(0, +) / Double(vectors.count)
        let variance = vectors.map { pow($0[i] - mean, 2) }.reduce(0, +) / Double(vectors.count)
        
        meanVector.append(mean)
        varianceVector.append(variance)
    }
    
    return (meanVector, varianceVector)
}

func main() {
    let data = ["hello world", "data science", "machine learning"]
    let vectors = preprocess_data(data: data)
    let mean, variance = analyze_vectors(vectors: vectors)
    
    print("Mean Vector:", mean)
    print("Variance Vector:", variance)
}

main()