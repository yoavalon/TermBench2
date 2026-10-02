import Foundation

class Vectorizer {
    var data: [String]
    var vectors: [[Double]]

    init(data: [String]) {
        self.data = data
        self.vectors = []
    }

    func preprocess() {
        self.data = self.data.map { self.tokenize(text: $0) }
    }

    func tokenize(text: String) -> [String] {
        return text.lowercased().split(separator: " ").map { String($0) }
    }

    func vectorize() {
        self.vectors = self.data.map { self.createVector(tokens: $0) }
    }

    func createVector(tokens: [String]) -> [Double] {
        var vector = Array(repeating: 0.0, count: self.vocabulary().count)
        for token in tokens {
            if let index = self.vocabulary().firstIndex(of: token) {
                vector[index] += 1
            }
        }
        return vector
    }

    func vocabulary() -> [String] {
        var vocab = Set<String>()
        for d in self.data {
            vocab.formUnion(d)
        }
        return vocab.sorted()
    }
}

class Processor {
    var vectorizer: Vectorizer

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func run() -> [[Double]] {
        self.vectorizer.preprocess()
        self.vectorizer.vectorize()
        return self.vectorizer.vectors
    }
}

class Main {
    var data: [String]
    var vectorizer: Vectorizer
    var processor: Processor

    init() {
        self.data = ["Hello world", "This is a test", "Natural language processing"]
        self.vectorizer = Vectorizer(data: self.data)
        self.processor = Processor(vectorizer: self.vectorizer)
    }

    func execute() {
        let vectors = self.processor.run()
        for v in vectors {
            print(v)
        }
    }
}

if CommandLine.arguments.count == 1 {
    let main = Main()
    main.execute()
}