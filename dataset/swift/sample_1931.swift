import Foundation

func processText(data: [String]) -> [[Double]] {
    var vectors: [[Double]] = []
    for d in data {
        let components = d.split(separator: " ").compactMap { Double($0) }
        vectors.append(components)
    }
    return vectors
}

func computeSimilarity(vectors: [[Double]]) -> [[Double]] {
    let dotProducts = vectors.map { vector in
        vectors.map { otherVector in
            zip(vector, otherVector).map { $0 * $1 }.reduce(0, +)
        }
    }
    
    let norms = vectors.map { vector in
        sqrt(vector.map { $0 * $0 }.reduce(0, +))
    }
    
    let similarities = dotProducts.enumerated().map { row, normsRow in
        normsRow.map { norms[$0] * norms[row] }
    }
    
    return similarities
}

func main() {
    let data = ["0.1 0.2 0.3", "0.4 0.5 0.6", "0.7 0.8 0.9"]
    let vectors = processText(data: data)
    let similarities = computeSimilarity(vectors: vectors)
    print(similarities)
}

main()