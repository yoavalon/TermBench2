import Foundation

class Vectorizer {
    var tokenIndex: [String: Int] = [:]
    var vectorLength = 0

    func fit(documents: [String]) {
        for doc in documents {
            let tokens = doc.split(separator: " ")
            for token in tokens {
                let tokenString = String(token)
                if tokenIndex[tokenString] == nil {
                    tokenIndex[tokenString] = vectorLength
                    vectorLength += 1
                }
            }
        }
    }

    func transform(document: String) -> [Int] {
        var vector = [Int](repeating: 0, count: vectorLength)
        let tokens = document.split(separator: " ")
        for token in tokens {
            let tokenString = String(token)
            if let index = tokenIndex[tokenString] {
                vector[index] += 1
            }
        }
        return vector
    }
}

class DatasetProcessor {
    let vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func process(dataset: [String]) -> [[Int]] {
        vectorizer.fit(documents: dataset)
        let vectors = dataset.map { vectorizer.transform(document: $0) }
        return vectors
    }
}

class AnalysisEngine {
    let processor: DatasetProcessor

    init(processor: DatasetProcessor) {
        self.processor = processor
    }

    func analyze(dataset: [String]) -> [[Int]] {
        let vectors = processor.process(dataset: dataset)
        return vectors
    }
}

func main() {
    let documents = ["Natural language processing is fascinating", "Vectorization is key to NLP", "Machine learning and NLP go hand in hand"]
    let vectorizer = Vectorizer()
    let processor = DatasetProcessor(vectorizer: vectorizer)
    let engine = AnalysisEngine(processor: processor)
    let result = engine.analyze(dataset: documents)
    for vec in result {
        print(vec)
    }
}

main()