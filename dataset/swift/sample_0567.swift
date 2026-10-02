import Foundation

class Vectorizer {
    var vocabSize: Int
    var wordToIndex: [String: Int] = [:]
    var indexToWord: [Int: String] = [:]

    init(vocabSize: Int) {
        self.vocabSize = vocabSize
    }

    func fit(corpus: [String]) {
        var words = Set<String>()
        for text in corpus {
            words.formUnion(text.split(separator: " ").map { String($0) })
        }
        for (idx, word) in words.enumerated() {
            wordToIndex[word] = idx
            indexToWord[idx] = word
        }
    }

    func transform(text: String) -> [Double] {
        var vector = [Double](repeating: 0.0, count: vocabSize)
        for word in text.split(separator: " ").map { String($0) } {
            if let index = wordToIndex[word] {
                vector[index] += 1
            }
        }
        return vector
    }
}

class Processor {
    var vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func processData(data: [String]) -> [[Double]] {
        var vectors: [[Double]] = []
        for text in data {
            vectors.append(vectorizer.transform(text: text))
        }
        return vectors
    }
}

func main() {
    let corpus = ["the quick brown fox jumps over the lazy dog", "hello world", "data science is fascinating", "machine learning is powerful", "python is versatile"]
    let vectorizer = Vectorizer(vocabSize: 50)
    vectorizer.fit(corpus: corpus)
    let processor = Processor(vectorizer: vectorizer)
    var processedData = processor.processData(data: corpus)
    while true {
        let newText = "exploring new boundaries"
        let newVector = vectorizer.transform(text: newText)
        processedData.append(newVector)
    }
}

main()