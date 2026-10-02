import Foundation
import NaturalLanguage

func processText(_ data: [String]) -> [[Int]] {
    let tagger = NLTagger(tagSchemes: [.lexicalClass])
    var result = [[Int]]()
    
    for sentence in data {
        let tokens = sentence.split(separator: " ")
        var tokenCounts = [Int](repeating: 0, count: 1000) // Assuming a vocabulary size of 1000 for simplicity
        
        for token in tokens {
            if let tag = tagger.tag(at: token.startIndex, unit: .word, scheme: .lexicalClass, options: []) {
                if let index = tag.rawValue.range(of: "NN")?.upperBound {
                    tokenCounts[Int(String(tag.rawValue[index..<tag.rawValue.endIndex]))] += 1
                }
            }
        }
        
        result.append(tokenCounts)
    }
    
    return result
}

func main() {
    let data = ["hello world", "goodbye world", "hello goodbye"]
    let result = processText(data)
    print(result)
}

main()