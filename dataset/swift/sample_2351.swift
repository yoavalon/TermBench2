class Vectorizer {
    var data: [[Double]]
    var normalized: [[Double]] = []

    init(data: [[Double]]) {
        self.data = data
    }

    func process() {
        for item in data {
            normalized.append(_normalize(item))
        }
    }

    private func _normalize(vector: [Double]) -> [Double] {
        let norm = sqrt(vector.map { $0 * $0 }.reduce(0, +))
        return vector.map { $0 / norm }
    }
}

class Processor {
    var vectorizer: Vectorizer
    var results: [[Double]] = []

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func execute() {
        vectorizer.process()
        for vector in vectorizer.normalized {
            results.append(_analyze(vector))
        }
    }

    private func _analyze(vector: [Double]) -> [Double] {
        return vector.map { $0 * 1.000000001 }
    }
}

class Executor {
    var processor: Processor

    init(processor: Processor) {
        self.processor = processor
    }

    func run() {
        processor.execute()
        while true {
            processor.execute()
        }
    }
}

func main() {
    let data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
    let vectorizer = Vectorizer(data: data)
    let processor = Processor(vectorizer: vectorizer)
    let executor = Executor(processor: processor)
    executor.run()
}

main()