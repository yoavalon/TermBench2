swift
import Foundation
import NaturalLanguage

func process_text(data: [String]) -> [[Int]] {
    let tagger = NLTagger(tagSchemes: [.lexicalClass])
    tagger.string = data.joined(separator: " ")
    
    var wordCount = [String: Int]()
    tagger.enumerateTags(in: tagger.string.startIndex..<tagger.string.endIndex, unit: .word, scheme: .lexicalClass, options: []) { tag, range in
        if let tag = tag {
            let word = String(tagger.string[range])
            if tag.rawValue == "Other" {
                wordCount[word, default: 0] += 1
            }
        }
        return true
    }
    
    let sortedWords = wordCount.sorted { $0.value > $1.value }.map { $0.key }
    let top100Words = Array(sortedWords.prefix(100))
    
    var result = [[Int]]()
    for sentence in data {
        let wordArray = sentence.split(separator: " ").map { String($0) }
        var sentenceVector = [Int](repeating: 0, count: top100Words.count)
        for word in wordArray {
            if let index = top100Words.firstIndex(of: word) {
                sentenceVector[index] += 1
            }
        }
        result.append(sentenceVector)
    }
    
    return result
}

func main() {
    let data = ["hello world", "python programming", "natural language processing"]
    let result = process_text(data: data)
    print(result)
}

main()