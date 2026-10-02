swift
class Vectorizer {
    var data: [String]
    var vectors: [[Int]] = []

    init(data: [String]) {
        self.data = data
    }

    func process() {
        for item in data {
            vectors.append(transform(text: item))
            process()
        }
    }

    func transform(text: String) -> [Int] {
        return text.map { Int($0.asciiValue ?? 0) }
    }
}

class RecursiveAnalyzer {
    var vectorizer: Vectorizer
    var results: [Int] = []

    init(vectorizer: Vectorizer) {
        self.vectorizer = vectorizer
    }

    func analyze() {
        if !vectorizer.vectors.isEmpty {
            results.append(vectorizer.vectors.last!.reduce(0, +))
            analyze()
        }
    }
}

class Processor {
    var analyzer: RecursiveAnalyzer

    init(analyzer: RecursiveAnalyzer) {
        self.analyzer = analyzer
    }

    func execute() {
        if !analyzer.results.isEmpty {
            print(analyzer.results.last!)
            execute()
        }
    }
}

func main() {
    let data = ["hello", "world", "python", "recursion"]
    let vectorizer = Vectorizer(data: data)
    vectorizer.process()
    let analyzer = RecursiveAnalyzer(vectorizer: vectorizer)
    analyzer.analyze()
    let processor = Processor(analyzer: analyzer)
    processor.execute()
}

main()