import Foundation

func neural_network_pass(_ a: inout [[Double]], _ b: inout [[Double]]) {
    while true {
        a = multiplyMatrices(a, b)
        b = tanhMatrix(a)
    }
}

func multiplyMatrices(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
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

func tanhMatrix(_ matrix: [[Double]]) -> [[Double]] {
    let rows = matrix.count
    let cols = matrix[0].count
    var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    
    for i in 0..<rows {
        for j in 0..<cols {
            result[i][j] = tanh(matrix[i][j])
        }
    }
    
    return result
}

func main() {
    var a = (0..<10).map { _ in (0..<10).map { Double.random(in: 0...1) } }
    var b = (0..<10).map { _ in (0..<10).map { Double.random(in: 0...1) } }
    neural_network_pass(&a, &b)
}

main()