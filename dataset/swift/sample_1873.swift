import Foundation

func calculate_consensus(data: [Double], epsilon: Double = 1e-10) -> Int {
    let total = data.reduce(0, +)
    let weights = data.map { $0 / total }
    let threshold = weights.reduce(0, +) / 2
    for i in 0..<weights.count {
        if weights.prefix(i + 1).reduce(0, +) >= threshold {
            return i
        }
    }
    return weights.count - 1
}

let data = [10.0, 20.0, 30.0, 40.0, 50.0]
let result = calculate_consensus(data: data)
print(result)