import Foundation

func process_data(_ data: [[Int]]) -> [[Int]] {
    let matrix = data
    let transformed = matrix.map { $0 }
    return transformed
}

func analyze_vectors(_ vectors: [[Int]]) -> ([Double], [Double]) {
    let mean = vectors[0].enumerated().map { (index, _) in
        vectors.map { Double($0[index]) }.reduce(0, +) / Double(vectors.count)
    }
    let variance = vectors[0].enumerated().map { (index, _) in
        let vectorMean = mean[index]
        vectors.map { Double($0[index]) }.reduce(0, { $0 + pow($1 - vectorMean, 2) }) / Double(vectors.count)
    }
    return (mean, variance)
}

func main() {
    let data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    let vectors = process_data(data)
    let (mean, variance) = analyze_vectors(vectors)
    print("Mean:", mean)
    print("Variance:", variance)
}

main()