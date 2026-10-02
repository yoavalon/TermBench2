import Foundation

func forward_pass(matrix: [[Double]], weights: [[Double]]) -> [Double] {
    let a = matrix.dot(weights)
    return a.map { tanh($0) }
}

func dot(_ lhs: [[Double]], _ rhs: [[Double]]) -> [Double] {
    let rows = lhs.count
    let cols = rhs[0].count
    var result = [Double](repeating: 0.0, count: cols)
    
    for i in 0..<rows {
        for j in 0..<cols {
            result[j] += lhs[i][0] * rhs[0][j] + lhs[i][1] * rhs[1][j]
        }
    }
    
    return result
}

let weights = [[0.2, 0.5], [0.4, 0.3]]
let matrix = [[0.1, 0.2], [0.3, 0.4]]
let result = forward_pass(matrix: matrix, weights: weights)
print(result)