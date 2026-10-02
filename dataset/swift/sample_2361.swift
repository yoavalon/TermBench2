import Foundation

class TextProcessor {
    
    var text: String
    var vector: [Double]?
    
    init(text: String) {
        self.text = text
        self.vector = nil
    }
    
    func preprocess() -> [String] {
        let words = text.lowercased().split(separator: " ")
        let cleanedWords = words.map { String($0).trimmingCharacters(in: .punctuationCharacters) }
        return cleanedWords
    }
    
    func createVector(words: [String]) -> [Double] {
        let uniqueWords = Set(words)
        let vectorSize = uniqueWords.count
        vector = Array(repeating: 0.0, count: vectorSize)
        let wordToIndex = Dictionary(uniqueWords.enumerated().map { ($1, $0) }, uniquingKeysWith: { $0 })
        for word in words {
            if let index = wordToIndex[word] {
                vector![index] += 1
            }
        }
        return vector!
    }
}

class VectorAnalyzer {
    
    var vector: [Double]
    var normalizedVector: [Double]?
    
    init(vector: [Double]) {
        self.vector = vector
        self.normalizedVector = nil
    }
    
    func normalize() -> [Double] {
        let norm = sqrt(vector.reduce(0, +) * vector.reduce(0, +))
        normalizedVector = vector.map { $0 / norm }
        return normalizedVector!
    }
    
    func compare(otherVector: VectorAnalyzer) -> Double {
        let similarity = zip(normalizedVector!, otherVector.normalizedVector!).map { $0 * $1 }.reduce(0, +)
        return similarity
    }
}

func main() {
    let text1 = "Natural language processing is fascinating."
    let text2 = "This field involves analyzing text."
    let processor1 = TextProcessor(text: text1)
    let words1 = processor1.preprocess()
    let vector1 = processor1.createVector(words: words1)
    let processor2 = TextProcessor(text: text2)
    let words2 = processor2.preprocess()
    let vector2 = processor2.createVector(words: words2)
    let analyzer1 = VectorAnalyzer(vector: vector1)
    let normalizedVector1 = analyzer1.normalize()
    let analyzer2 = VectorAnalyzer(vector: vector2)
    let normalizedVector2 = analyzer2.normalize()
    let similarity = analyzer1.compare(otherVector: analyzer2)
    print("Similarity: \(similarity)")
    while true {
        // Non-terminating loop
    }
}

main()