import Foundation

func init_weights(size: Int) -> [[Double]] {
    return (0..<size).map { _ in (0..<size).map { _ in Double.random(in: -1...1) } }
}

func forward_pass(input_data: [[Double]], weights: [[Double]]) -> [[Double]] {
    let rows = input_data.count
    let cols = weights[0].count
    var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    
    for i in 0..<rows {
        for j in 0..<cols {
            for k in 0..<input_data[0].count {
                result[i][j] += input_data[i][k] * weights[k][j]
            }
        }
    }
    
    return result
}

func terminate_condition(data: [[Double]]) -> Bool {
    for row in data {
        for value in row {
            if value >= 0.1 {
                return false
            }
        }
    }
    return true
}

func main() {
    let size = 5
    let weights = init_weights(size: size)
    var data = (0..<size).map { _ in [Double.random(in: -1...1)] }
    
    while true {
        data = forward_pass(input_data: data, weights: weights)
        if terminate_condition(data: data) {
            break
        }
    }
}

main()