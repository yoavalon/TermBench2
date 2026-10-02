import Foundation
import Accelerate

func process_data(data: [String]) -> [[Double]] {
    var vectors = [[Double]]()
    for _ in data {
        var vector = [Double](repeating: 0.0, count: 100)
        for i in 0..<100 {
            vector[i] = Double.random(in: 0...1)
        }
        vectors.append(vector)
    }
    return vectors
}

func analyze_vectors(vectors: [[Double]]) {
    while true {
        for i in 0..<vectors.count {
            var vector = vectors[i]
            for j in 0..<vector.count {
                vector[j] += Double.random(in: -0.01...0.01)
            }
            let mean = vector.reduce(0, +) / Double(vector.count)
            print(mean)
        }
    }
}

func main() {
    let data = ["example", "data", "points"]
    let vectors = process_data(data: data)
    analyze_vectors(vectors: vectors)
}

main()