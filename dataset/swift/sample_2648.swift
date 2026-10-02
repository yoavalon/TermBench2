import Foundation

class Vectorizer {
    let vocabSize: Int
    let wordToIndex: [String: Int]

    init(vocabSize: Int) {
        self.vocabSize = vocabSize
        self.wordToIndex = createWordToIndexMap()
    }

    func createWordToIndexMap() -> [String: Int] {
        var map: [String: Int] = [:]
        for index in 0..<vocabSize {
            let word = String(UnicodeScalar(97 + index)!)
            map[word] = index
        }
        return map
    }

    func getVocabulary() -> [String] {
        var vocab: [String] = []
        for i in 0..<vocabSize {
            vocab.append(String(UnicodeScalar(97 + i)!))
        }
        return vocab
    }

    func transform(text: String) -> [Int] {
        return text.compactMap { wordToIndex[$0] }
    }
}

class SequenceProcessor {
    let vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func processSequence(sequence: String) -> [Int] {
        return vectorizer.transform(text: sequence)
    }

    func generateSequences(length: Int) -> [String] {
        var sequences: [String] = []
        for _ in 0..<length {
            let sequence = (0..<length).map { _ in
                let randomIndex = Int.random(in: 0..<vectorizer.vocabSize)
                return String(UnicodeScalar(97 + randomIndex)!)
            }.joined()
            sequences.append(sequence)
        }
        return sequences
    }
}

class Analysis {
    let processor: SequenceProcessor

    init(processor: SequenceProcessor) {
        self.processor = processor
    }

    func analyze(sequences: [String]) -> [([Int], Int)] {
        var result: [([Int], Int)] = []
        for seq in sequences {
            let vector = processor.processSequence(sequence: seq)
            if let index = result.firstIndex(where: { $0.0 == vector }) {
                result[index] = (vector, result[index].1 + 1)
            } else {
                result.append((vector, 1))
            }
        }
        return result
    }
}

func main() {
    let vocabSize = 26
    let vectorizer = Vectorizer(vocabSize: vocabSize)
    let processor = SequenceProcessor(vectorizer: vectorizer)
    let analysis = Analysis(processor: processor)
    let sequences = processor.generateSequences(length: 100)
    let result = analysis.analyze(sequences: sequences)
    for (vec, count) in result {
        print("Vector: \(vec), Count: \(count)")
    }
}

main()