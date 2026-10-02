import Foundation

func matrix_forward_pass() {
    while true {
        let a = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        let b = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        let c = multiply_matrices(a, b)
        let d = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        let e = multiply_matrices(c, d)
        let f = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        let g = multiply_matrices(e, f)
    }
}

func multiply_matrices(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let rowCountA = a.count
    let colCountA = a[0].count
    let rowCountB = b.count
    let colCountB = b[0].count
    
    guard colCountA == rowCountB else {
        fatalError("Matrix dimensions do not match for multiplication")
    }
    
    var result = Array(repeating: Array(repeating: 0.0, count: colCountB), count: rowCountA)
    
    for i in 0..<rowCountA {
        for j in 0..<colCountB {
            for k in 0..<colCountA {
                result[i][j] += a[i][k] * b[k][j]
            }
        }
    }
    
    return result
}

matrix_forward_pass()