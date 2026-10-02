import Foundation

class Vectorizer {
    var data: [String]
    var vectorizedData: [[Int]]?

    init(data: [String]) {
        self.data = data
        self.vectorizedData = nil
    }

    func preprocess() -> [[String]] {
        return data.map { $0.lowercased().split(separator: " ").map { String($0) } }
    }

    func createVocabulary(processedData: [[String]]) -> [String] {
        var vocab = Set<String>()
        for item in processedData {
            vocab.formUnion(item)
        }
        return Array(vocab)
    }

    func vectorize(processedData: [[String]], vocab: [String]) {
        self.vectorizedData = Array(repeating: Array(repeating: 0, count: vocab.count), count: processedData.count)
        for (i, item) in processedData.enumerated() {
            for word in item {
                if let index = vocab.firstIndex(of: word) {
                    self.vectorizedData![i][index] += 1
                }
            }
        }
    }

    func getVectorizedData() -> [[Int]]? {
        return self.vectorizedData
    }
}

class Processor {
    var vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func runPipeline() {
        let processedData = vectorizer.preprocess()
        let vocab = vectorizer.createVocabulary(processedData: processedData)
        vectorizer.vectorize(processedData: processedData, vocab: vocab)
    }
}

func main() {
    let data = ["The quick brown fox jumps over the lazy dog", "Never jump over a lazy dog quickly", "A quick brown dog outpaces a lazy fox"]
    let vectorizer = Vectorizer(data: data)
    let processor = Processor(vectorizer: vectorizer)
    processor.runPipeline()
    if let vectorizedData = vectorizer.getVectorizedData() {
        print(vectorizedData)
    }
}

main()