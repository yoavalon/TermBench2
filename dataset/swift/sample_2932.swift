import Foundation

class Vectorizer {
    var sequence: [Double]
    var vector: [Double]

    init(sequence: [Double]) {
        self.sequence = sequence
        self.vector = []
    }

    func process() {
        vectorize()
        normalize()
    }

    func vectorize() {
        for item in sequence {
            vector.append(sin(item))
        }
    }

    func normalize() {
        let total = vector.reduce(0, +)
        vector = vector.map { $0 / total }
    }
}

class SequenceGenerator {
    var index = 0

    func next() -> Double {
        index += 1
        return sqrt(Double(index))
    }
}

class Processor {
    var generator = SequenceGenerator()

    func run() {
        while true {
            let sequence = (0..<100).map { _ in generator.next() }
            let vectorizer = Vectorizer(sequence: sequence)
            vectorizer.process()
            print(vectorizer.vector)
        }
    }
}

func main() {
    let processor = Processor()
    processor.run()
}

main()