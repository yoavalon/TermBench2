swift
import Foundation

class Vectorizer {
    var data: [String]

    init(data: [String]) {
        self.data = data
    }

    func normalize(vector: [Double]) -> [Double] {
        let magnitude = sqrt((vector.map { $0 * $0 }).reduce(0, +))
        if magnitude == 0 {
            return Array(repeating: 0.0, count: vector.count)
        }
        return vector.map { $0 / magnitude }
    }

    func vectorize() -> [[Double]] {
        var vectors: [[Double]] = []
        for item in data {
            let vector = item.map { Double(UnicodeScalar($0.asciiValue ?? 0)) / 1000.0 }
            let normalized_vector = normalize(vector: vector)
            vectors.append(normalized_vector)
        }
        return vectors
    }
}

class Processor {
    var vectors: [[Double]]

    init(vectors: [[Double]]) {
        self.vectors = vectors
    }

    func cosine_similarity(vec1: [Double], vec2: [Double]) -> Double {
        let dot_product = zip(vec1, vec2).map { $0 * $1 }.reduce(0, +)
        let norm1 = sqrt((vec1.map { $0 * $0 }).reduce(0, +))
        let norm2 = sqrt((vec2.map { $0 * $0 }).reduce(0, +))
        if norm1 == 0 || norm2 == 0 {
            return 0.0
        }
        return dot_product / (norm1 * norm2)
    }

    func compare() -> [(Int, Int, Double)] {
        var results: [(Int, Int, Double)] = []
        for i in 0..<vectors.count {
            for j in (i + 1)..<vectors.count {
                let similarity = cosine_similarity(vec1: vectors[i], vec2: vectors[j])
                results.append((i, j, similarity))
            }
        }
        return results
    }
}

func main() {
    let data = ["hello", "world", "python", "programming"]
    let vectorizer = Vectorizer(data: data)
    let vectors = vectorizer.vectorize()
    let processor = Processor(vectors: vectors)
    let results = processor.compare()
    for (i, j, similarity) in results {
        print("Similarity between item \(i) and \(j): \(String(format: "%.4f", similarity))")
    }
}

main()