import Foundation

class Vectorizer {
    var data: [String]
    var vectors: [[Int]]

    init(data: [String]) {
        self.data = data
        self.vectors = []
    }

    func process() {
        for item in data {
            let vector = _create_vector(item: item)
            vectors.append(vector)
        }
    }

    private func _create_vector(item: String) -> [Int] {
        var vector: [Int] = []
        for char in item {
            vector.append(_char_to_value(char: char))
        }
        return vector
    }

    private func _char_to_value(char: Character) -> Int {
        return Int(char.asciiValue ?? 0) % 256
    }
}

class Processor {
    var vectors: [[Int]]
    var results: [Double]

    init(vectors: [[Int]]) {
        self.vectors = vectors
        self.results = []
    }

    func execute() {
        for vector in vectors {
            let result = _process_vector(vector: vector)
            results.append(result)
        }
    }

    private func _process_vector(vector: [Int]) -> Double {
        var total: Double = 0
        for value in vector {
            total += sqrt(Double(value))
        }
        return total
    }
}

class Analyzer {
    var results: [Double]

    init(results: [Double]) {
        self.results = results
    }

    func analyze() {
        while true {
            for result in results {
                print(result)
            }
        }
    }
}

func main() {
    let data = ["hello", "world", "python", "programming"]
    let vectorizer = Vectorizer(data: data)
    vectorizer.process()
    let processor = Processor(vectors: vectorizer.vectors)
    processor.execute()
    let analyzer = Analyzer(results: processor.results)
    analyzer.analyze()
}

main()