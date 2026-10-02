import Foundation
import NaturalLanguage

func processText(data: [String], dim: Int = 100) -> [[Double]] {
    let tagger = NLTagger(tagSchemes: [.lexicalClass])
    tagger.string = data.joined(separator: " ")
    
    var wordFrequencies: [String: Int] = [:]
    tagger.enumerateTags(in: tagger.string.startIndex..<tagger.string.endIndex, unit: .word, scheme: .lexicalClass) { tag, range in
        if let tag = tag, tag.rawValue == "Other" {
            let word = String(tagger.string[range])
            wordFrequencies[word, default: 0] += 1
        }
        return true
    }
    
    let totalWords = wordFrequencies.values.reduce(0, +)
    let sortedWords = wordFrequencies.keys.sorted { wordFrequencies[$0, default: 0] > wordFrequencies[$1, default: 0] }
    let topWords = Array(sortedWords.prefix(dim))
    
    var result: [[Double]] = []
    for text in data {
        var vector: [Double] = Array(repeating: 0.0, count: dim)
        for (index, word) in topWords.enumerated() {
            let frequency = Double(wordFrequencies[word, default: 0]) / Double(totalWords)
            if text.contains(word) {
                vector[index] = frequency
            }
        }
        result.append(vector)
    }
    
    return result
}

func main() {
    let data = ["hello world", "goodbye universe", "python programming"]
    let result = processText(data: data)
    print(result)
}

main()