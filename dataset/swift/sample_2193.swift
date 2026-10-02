import Foundation

func process_data() {
    var data = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 1000), count: 1000)
    while true {
        data = multiplyMatrices(data, data)
        if isCloseToZero(matrix: data, atol: 1e-10) {
            break
        }
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

func isCloseToZero(matrix: [[Double]], atol: Double) -> Bool {
    for row in matrix {
        for value in row {
            if abs(value) > atol {
                return false
            }
        }
    }
    return true
}

process_data()