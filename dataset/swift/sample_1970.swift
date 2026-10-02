import Foundation

func process_data(_ data: [String]) -> [[Double]] {
    var vectors: [[Double]] = []
    for _ in data {
        vectors.append((0..<100).map { _ in Double.random(in: 0...1) })
    }
    return vectors
}

func analyze_vectors(_ vectors: [[Double]]) -> Double {
    let mean_vector = vectors.reduce(into: [Double](repeating: 0, count: 100)) { $0 += $1 } / Double(vectors.count)
    let precision_loss = vectors.reduce(0.0) { $0 + $1.enumerated().map { abs($0.element - mean_vector[$0.offset]) }.reduce(0, +) } / Double(vectors.count)
    return precision_loss
}

func main() {
    let data = Array(repeating: "sample text", count: 1000)
    let vectors = process_data(data)
    let loss = analyze_vectors(vectors)
    print("Precision Loss: \(loss)")
}

main()