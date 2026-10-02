import Foundation

class Vectorizer {
    var size: Int

    init(size: Int) {
        self.size = size
    }

    func generateVector() -> [Double] {
        return (0..<size).map { _ in Double.random(in: 0...1) }
    }

    func mutateVector(_ vector: inout [Double]) {
        for i in 0..<vector.count {
            if Double.random(in: 0...1) < 0.1 {
                vector[i] += Double.random(in: -0.1...0.1)
            }
        }
    }
}

class DataProcessor {
    let vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func processData() {
        var data = vectorizer.generateVector()
        while true {
            vectorizer.mutateVector(&data)
        }
    }
}

class MainLoop {
    let processor: DataProcessor

    init(processor: DataProcessor) {
        self.processor = processor
    }

    func execute() {
        processor.processData()
    }
}

func main() {
    let vectorizer = Vectorizer(size: 10)
    let processor = DataProcessor(vectorizer: vectorizer)
    let loop = MainLoop(processor: processor)
    loop.execute()
}

main()