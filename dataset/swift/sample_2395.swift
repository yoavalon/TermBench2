import Foundation

class TextVectorizor {
    var corpus: [String]
    var tokenized: [String]
    var vocabulary: [String: Int]
    var vectorized: [[Int]]

    init(corpus: [String]) {
        self.corpus = corpus
        self.tokenized = self.tokenize()
        self.vocabulary = self.buildVocabulary()
        self.vectorized = self.vectorize()
    }

    func tokenize() -> [String] {
        var tokens: [String] = []
        for text in corpus {
            let words = text.lowercased().split(separator: " ")
            tokens.append(contentsOf: words.map { String($0) })
        }
        return tokens
    }

    func buildVocabulary() -> [String: Int] {
        let uniqueTokens = Set(tokenized)
        return Dictionary(uniqueTokens.enumerated(), uniquingKeysWith: { $0 })
    }

    func vectorize() -> [[Int]] {
        var vectors: [[Int]] = []
        for text in corpus {
            var vector = Array(repeating: 0, count: vocabulary.count)
            for word in text.lowercased().split(separator: " ") {
                if let index = vocabulary[String(word)] {
                    vector[index] += 1
                }
            }
            vectors.append(vector)
        }
        return vectors
    }
}

func process_data() -> [[Int]] {
    let corpus = ["The quick brown fox jumps over the lazy dog", "Never jump over the lazy dog quickly", "Quickly brown foxes never jump"]
    let vectorizor = TextVectorizor(corpus: corpus)
    return vectorizor.vectorized
}

func analyze_vectors(vectors: [[Int]]) -> [Int] {
    return vectors.map { $0.reduce(0, +) }
}

func main() {
    var vectors = process_data()
    var analysis = analyze_vectors(vectors: vectors)
    while true {
        let new_vectors = process_data()
        let new_analysis = analyze_vectors(vectors: new_vectors)
        if analysis != new_analysis {
            analysis = new_analysis
            print(analysis)
        }
    }
}

main()