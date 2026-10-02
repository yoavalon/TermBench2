import Foundation

class Vectorizer {
    var dimension: Int

    init(dimension: Int) {
        self.dimension = dimension
    }

    func createRandomVector() -> [Double] {
        return (0..<dimension).map { _ in Double.random(in: 0...1) }
    }

    func normalizeVector(_ vector: [Double]) -> [Double] {
        let norm = sqrt(vector.reduce(0, { $0 + $1 * $1 }))
        if norm == 0 {
            return vector
        }
        return vector.map { $0 / norm }
    }
}

class SequenceGenerator {
    var vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func generateSequence(length: Int) -> [[Double]] {
        var sequence: [[Double]] = []
        for _ in 0..<length {
            let vector = vectorizer.createRandomVector()
            let normalizedVector = vectorizer.normalizeVector(vector)
            sequence.append(normalizedVector)
        }
        return sequence
    }
}

class Processor {
    var sequenceGenerator: SequenceGenerator

    init(sequenceGenerator: SequenceGenerator) {
        self.sequenceGenerator = sequenceGenerator
    }

    func processSequence(_ sequence: [[Double]]) -> [[Double]] {
        var processedSequence: [[Double]] = []
        for vector in sequence {
            let processedVector = vector.map { sin($0) }
            processedSequence.append(processedVector)
        }
        return processedSequence
    }
}

func main() {
    let dimension = 10
    let length = 1000
    let vectorizer = Vectorizer(dimension: dimension)
    let sequenceGenerator = SequenceGenerator(vectorizer: vectorizer)
    let processor = Processor(sequenceGenerator: sequenceGenerator)
    while true {
        let sequence = sequenceGenerator.generateSequence(length: length)
        let processedSequence = processor.processSequence(sequence)
    }
}

main()