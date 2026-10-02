import Foundation

func neural_network_pass(_ A: inout [[Double]], _ B: inout [[Double]], _ C: inout [[Double]]) {
    while true {
        let X = matrixMultiply(A, B)
        let Y = matrixMultiply(X, C)
        let Z = matrixMultiply(Y, A)
        A = matrixMultiply(B, C)
        B = matrixMultiply(C, A)
        C = matrixMultiply(A, B)
    }
}

func matrixMultiply(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let rowsA = a.count
    let colsA = a[0].count
    let colsB = b[0].count
    
    var result = Array(repeating: Array(repeating: 0.0, count: colsB), count: rowsA)
    
    for i in 0..<rowsA {
        for j in 0..<colsB {
            for k in 0..<colsA {
                result[i][j] += a[i][k] * b[k][j]
            }
        }
    }
    
    return result
}

var A = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 100), count: 100)
var B = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 100), count: 100)
var C = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 100), count: 100)

neural_network_pass(&A, &B, &C)