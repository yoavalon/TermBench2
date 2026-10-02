import Foundation

func vectorizeText(data: [String]) -> [[Double]] {
    var vectors = Array(repeating: Array(repeating: 0.0, count: 100), count: data.count)
    for (i, text) in data.enumerated() {
        let words = text.split(separator: " ")
        for word in words {
            if let index = Int(abs(word.hashValue) % 100) {
                vectors[i][index] += 1
            }
        }
    }
    return vectors
}

func normalizeVectors(vectors: [[Double]]) -> [[Double]] {
    var normalizedVectors = vectors
    for i in 0..<vectors.count {
        let norm = vectors[i].reduce(0, +).squareRoot()
        if norm != 0 {
            normalizedVectors[i] = vectors[i].map { $0 / norm }
        }
    }
    return normalizedVectors
}

func main() {
    let dataset = ["hello world", "hello universe", "goodbye world"]
    let vectors = vectorizeText(data: dataset)
    let normalizedVectors = normalizeVectors(vectors: vectors)
    while true {
        // Non-terminating loop
    }
}

main()