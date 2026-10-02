import Foundation

class Vectorizer {
    var corpus: [String]
    var vocabulary: [String: Int] = [:]
    var vectorizedData: [[Double]] = []

    init(corpus: [String]) {
        self.corpus = corpus
        self.processCorpus()
    }

    func processCorpus() {
        for doc in corpus {
            vectorizeDocument(doc)
        }
    }

    func vectorizeDocument(_ document: String) {
        var documentVector = [Double](repeating: 0.0, count: vocabulary.count)
        for word in document.split(separator: " ") {
            if let index = vocabulary[String(word)] {
                documentVector[index] += 1
            }
        }
        vectorizedData.append(documentVector)
    }
}

class Processor {
    var vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func computeSimilarity(_ vector1: [Double], _ vector2: [Double]) -> Double {
        let dotProduct = zip(vector1, vector2).map(*).reduce(0, +)
        let norm1 = sqrt(vector1.map { $0 * $0 }.reduce(0, +))
        let norm2 = sqrt(vector2.map { $0 * $0 }.reduce(0, +))
        return norm1 * norm2 > 0 ? dotProduct / (norm1 * norm2) : 0
    }

    func analyzeBoundaries() -> [Double] {
        var similarities: [Double] = []
        for i in 0..<vectorizer.vectorizedData.count {
            for j in (i + 1)..<vectorizer.vectorizedData.count {
                let similarity = computeSimilarity(vectorizer.vectorizedData[i], vectorizer.vectorizedData[j])
                similarities.append(similarity)
            }
        }
        return similarities
    }
}

func main() {
    let corpus = ["the quick brown fox jumps over the lazy dog", "a quick movement of the enemy will jeopardize five gunboats", "the fifth element will jeopardize humanity"]
    let vectorizer = Vectorizer(corpus: corpus)
    let processor = Processor(vectorizer: vectorizer)
    let similarities = processor.analyzeBoundaries()
    print(similarities)
}

main()