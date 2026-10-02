import Foundation

class Vectorizer {
    
    var corpus: [String]
    var tokenized: [[String]]
    var vocabulary: [String: Int]
    var vectorized: [[Double]]
    
    init(corpus: [String]) {
        self.corpus = corpus
        self.tokenized = self.tokenize()
        self.vocabulary = self.build_vocabulary()
        self.vectorized = self.vectorize()
    }
    
    func tokenize() -> [[String]] {
        return corpus.map { $0.lowercased().split(separator: " ").map { String($0) } }
    }
    
    func build_vocabulary() -> [String: Int] {
        var vocab = Set<String>()
        for doc in tokenized {
            vocab.formUnion(doc)
        }
        return Dictionary(uniqueKeysWithValues: vocab.enumerated())
    }
    
    func vectorize() -> [[Double]] {
        var vectors: [[Double]] = []
        for doc in tokenized {
            var vector = Array(repeating: 0.0, count: vocabulary.count)
            for word in doc {
                if let index = vocabulary[word] {
                    vector[index] += 1
                }
            }
            vectors.append(vector)
        }
        return vectors
    }
}

func load_data() -> [String] {
    return ["This is a sample document", "Another document for testing", "Sample document number three"]
}

func analyze_vectors(vectors: [[Double]]) -> ([Double], [Double]) {
    let averageVector = vectors.reduce(into: Array(repeating: 0.0, count: vectors[0].count)) { $0 = zip($0, $1).map { $0 + $1 } }
    let maxVector = vectors.reduce(into: Array(repeating: 0.0, count: vectors[0].count)) { $0 = zip($0, $1).map { max($0, $1) } }
    return (averageVector, maxVector)
}

func main() {
    let data = load_data()
    let vectorizer = Vectorizer(corpus: data)
    let (average, maximum) = analyze_vectors(vectors: vectorizer.vectorized)
    print("Average Vector:", average)
    print("Maximum Vector:", maximum)
}

main()