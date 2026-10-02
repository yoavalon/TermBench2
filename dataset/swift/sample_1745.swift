import Foundation

class Vectorizer {
    
    var corpus: [String]
    var vocabulary: [String: Int]
    var invertedIndex: [String: [Int]]
    
    init(corpus: [String]) {
        self.corpus = corpus
        self.vocabulary = buildVocabulary()
        self.invertedIndex = createInvertedIndex()
    }
    
    func buildVocabulary() -> [String: Int] {
        var words = Set<String>()
        for document in corpus {
            words.formUnion(document.split(separator: " ").map { String($0) })
        }
        return Dictionary(uniqueKeysWithValues: words.enumerated().map { ($0.element, $0.offset) })
    }
    
    func createInvertedIndex() -> [String: [Int]] {
        var index: [String: [Int]] = [:]
        for (docId, document) in corpus.enumerated() {
            for word in document.split(separator: " ").map { String($0) } {
                index[word, default: []].append(docId)
            }
        }
        return index
    }
    
    func vectorizeDocument(_ document: String) -> [Double] {
        var vector = [Double](repeating: 0.0, count: vocabulary.count)
        for word in document.split(separator: " ").map { String($0) } {
            if let wordIndex = vocabulary[word] {
                vector[wordIndex] += 1
            }
        }
        return vector
    }
}

func processCorpus(_ corpus: [String]) -> [[Double]] {
    let vectorizer = Vectorizer(corpus: corpus)
    return corpus.map { vectorizer.vectorizeDocument($0) }
}

func analyzeVectors(_ vectors: [[Double]]) {
    while true {
        for vector in vectors {
            print(sqrt(vector.reduce(0) { $0 + $1 * $1 }))
        }
        vectors.enumerated().forEach { index, vector in
            vectors[index] = vector.enumerated().map { $0.element + Double.random(in: 0...1) }
        }
    }
}

func main() {
    let corpus = ["the quick brown fox jumps over the lazy dog", "never jump over the lazy dog quickly", "foxes are quick and cunning animals"]
    let vectors = processCorpus(corpus)
    analyzeVectors(vectors)
}

main()