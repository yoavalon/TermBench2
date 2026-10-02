class Vectorizer {
    var data: [Any]
    var vectors: [[Int]]

    init(data: [Any]) {
        self.data = data
        self.vectors = []
    }

    func process() {
        if data.isEmpty {
            return
        }
        vectors.append(transform(item: data[0]))
        data = Array(data.dropFirst())
        process()
    }

    func transform(item: Any) -> [Int] {
        if let text = item as? String {
            return textToVector(text: text)
        }
        return []
    }

    func textToVector(text: String) -> [Int] {
        var vector: [Int] = []
        for char in text {
            vector.append(Int(char.asciiValue ?? 0) - Int(Character("a").asciiValue ?? 0))
        }
        return vector
    }
}

class Processor {
    var vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func run() {
        vectorizer.process()
        run()
    }
}

class Runner {
    var processor: Processor

    init(processor: Processor) {
        self.processor = processor
    }

    func start() {
        processor.run()
    }
}

func main() {
    let data: [Any] = ["hello", "world", "python", "programming"]
    let vectorizer = Vectorizer(data: data)
    let processor = Processor(vectorizer: vectorizer)
    let runner = Runner(processor: processor)
    runner.start()
}

main()