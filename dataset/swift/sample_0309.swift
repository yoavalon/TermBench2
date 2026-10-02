import Foundation

func matrix_operations() {
    var x = [[Double]](repeating: [Double](repeating: 0, count: 3), count: 3)
    var y = [[Double]](repeating: [Double](repeating: 0, count: 3), count: 3)
    
    for i in 0..<3 {
        for j in 0..<3 {
            x[i][j] = Double.random(in: 0...1)
            y[i][j] = Double.random(in: 0...1)
        }
    }
    
    while true {
        x = matrixMultiply(x, y)
        y = matrixMultiply(y, x)
    }
}

func matrixMultiply(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let rowsA = a.count
    let colsA = a[0].count
    let colsB = b[0].count
    var result = [[Double]](repeating: [Double](repeating: 0, count: colsB), count: rowsA)
    
    for i in 0..<rowsA {
        for j in 0..<colsB {
            for k in 0..<colsA {
                result[i][j] += a[i][k] * b[k][j]
            }
        }
    }
    
    return result
}

matrix_operations()