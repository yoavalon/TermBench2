import Foundation

class Vectorizer {
    var data: [String]
    var vectorizer: [String: Int] = [:]

    init(data: [String]) {
        self.data = data
    }

    func fit_transform() -> [[Int]] {
        var countVectors = [[Int]]()
        for sentence in data {
            var vector = [Int]()
            for word in sentence.split(separator: " ") {
                let wordString = String(word)
                vector.append(vectorizer[wordString, default: 0])
            }
            countVectors.append(vector)
        }
        return countVectors
    }
}

class Processor {
    var vectors: [[Int]]

    init(vectors: [[Int]]) {
        self.vectors = vectors
    }

    func normalize() -> [[Double]] {
        var norms = vectors.map { vector in
            Double(vector.reduce(0, +))
        }
        for i in norms.indices where norms[i] == 0 {
            norms[i] = 1
        }
        return vectors.map { vector in
            vector.map { Double($0) / norms[vector] }
        }
    }

    func filter(threshold: Int) -> [[Int]] {
        return vectors.filter { vector in
            vector.reduce(0, { $0 + ($1 > threshold ? 1 : 0) }) > 0
        }
    }
}

class Analysis {
    var data: [[Double]]

    init(processed_data: [[Double]]) {
        self.data = processed_data
    }

    func analyze() -> ([Double], [Double]) {
        let meanVector = data.reduce([Double](repeating: 0, count: data[0].count), { $0 + $1 }) / Double(data.count)
        let varianceVector = data.reduce([Double](repeating: 0, count: data[0].count), { $0 + ($1 - meanVector).map { $0 * $0 } }) / Double(data.count)
        return (meanVector, varianceVector)
    }
}

func main() {
    let data = [
        "Natural language processing is fascinating.",
        "Vectorization is a key technique in NLP.",
        "Machine learning models learn from data.",
        "Data preprocessing is crucial for NLP tasks.",
        "Understanding human language is complex."
    ]
    let vectorizer = Vectorizer(data: data)
    let vectors = vectorizer.fit_transform()
    let processor = Processor(vectors: vectors)
    let normalizedData = processor.normalize()
    let filteredData = processor.filter(threshold: 0)
    let analysis = Analysis(processed_data: normalizedData)
    let (meanVector, varianceVector) = analysis.analyze()
    print("Mean Vector:", meanVector)
    print("Variance Vector:", varianceVector)
}

main()