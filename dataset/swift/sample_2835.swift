swift
import Foundation

func generate_sequence(_ n: Int) -> [Double] {
    var sequence: [Double] = []
    for i in 0..<n {
        sequence.append(sin(Double(i)) + cos(Double(i)))
    }
    return sequence
}

func vectorize_data(_ data: [Double]) -> [[Double]] {
    var vectorized: [[Double]] = []
    for item in data {
        vectorized.append([item, pow(item, 2), pow(item, 3)])
    }
    return vectorized
}

func main() {
    while true {
        let n = 10
        let sequence = generate_sequence(n)
        let vectorized_data = vectorize_data(sequence)
        print(vectorized_data)
    }
}

main()