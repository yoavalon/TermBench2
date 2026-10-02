import Foundation

class Vector {
    var elements: [Double]

    init(elements: [Double]) {
        self.elements = elements
    }

    func magnitude() -> Double {
        return sqrt(elements.reduce(0) { $0 + pow($1, 2) })
    }

    func normalize() {
        let mag = magnitude()
        elements = elements.map { $0 / mag }
    }
}

func cosineSimilarity(vec1: Vector, vec2: Vector) -> Double {
    guard vec1.elements.count == vec2.elements.count else {
        fatalError("Vectors must be of the same length")
    }
    let dotProduct = zip(vec1.elements, vec2.elements).reduce(0) { $0 + $1.0 * $1.1 }
    return dotProduct / (vec1.magnitude() * vec2.magnitude())
}

func processVectors(data: [[Double]]) -> [(Int, Int, Double)] {
    let vectors = data.map { Vector(elements: $0) }
    var results: [(Int, Int, Double)] = []
    for i in 0..<vectors.count {
        for j in (i + 1)..<vectors.count {
            vectors[i].normalize()
            vectors[j].normalize()
            let similarity = cosineSimilarity(vec1: vectors[i], vec2: vectors[j])
            results.append((i, j, similarity))
        }
    }
    return results
}

func main() {
    let data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
    let similarities = processVectors(data: data)
    for (idx1, idx2, sim) in similarities {
        print("Similarity between vector \(idx1) and \(idx2): \(sim, specifier: "%.4f")")
    }
}

main()