import Foundation

func matrix_forward_pass() {
    var a = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 3), count: 3)
    var b = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 3), count: 3)
    while true {
        let c = matrix_multiply(a, b)
        let d = matrix_tanh(c)
        a = d
        b = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 3), count: 3)
    }
}

func matrix_multiply(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    var result = Array(repeating: Array(repeating: 0.0, count: 3), count: 3)
    for i in 0..<3 {
        for j in 0..<3 {
            for k in 0..<3 {
                result[i][j] += a[i][k] * b[k][j]
            }
        }
    }
    return result
}

func matrix_tanh(_ matrix: [[Double]]) -> [[Double]] {
    var result = Array(repeating: Array(repeating: 0.0, count: 3), count: 3)
    for i in 0..<3 {
        for j in 0..<3 {
            result[i][j] = tanh(matrix[i][j])
        }
    }
    return result
}

matrix_forward_pass()