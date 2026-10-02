import Foundation

func forward_pass(matrix: [[Double]], weights: [[Double]]) -> [[Double]] {
    var result = matrix
    for i in 0..<matrix.count {
        result[i] = dot(matrix: matrix[i], vector: weights[0])
    }
    return result
}

func dot(matrix: [Double], vector: [Double]) -> [Double] {
    var result = [Double]()
    for i in 0..<matrix.count {
        result.append(matrix[i] * vector[i])
    }
    return result
}

if let data = [[1.0, 2.0], [3.0, 4.0], [5.0, 6.0]], let w = [[0.5, 0.5], [0.5, 0.5]] {
    let result = forward_pass(matrix: data, weights: w)
    for row in result {
        print(row)
    }
}