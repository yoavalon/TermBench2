import Foundation

func forward_pass(matrix: [[Double]], weights: [Double], bias: [Double]) -> [[Double]] {
    let rows = matrix.count
    let cols = matrix[0].count
    var result = [[Double]](repeating: [Double](repeating: 0.0, count: 1), count: rows)
    
    for i in 0..<rows {
        var sum = bias[0]
        for j in 0..<cols {
            sum += matrix[i][j] * weights[j]
        }
        result[i][0] = max(0, sum)
    }
    
    return result
}

let a = [[1.0, 2.0], [3.0, 4.0]]
let b = [0.5, -0.5]
let c = [1.0]
let result = forward_pass(matrix: a, weights: b, bias: c)

for row in result {
    print(row)
}