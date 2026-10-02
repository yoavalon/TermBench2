import Foundation

func processMatrix(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let c = multiplyMatrices(a, b)
    let cT = transposeMatrix(c)
    let d = addMatrices(c, cT)
    return d
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

func transposeMatrix(_ matrix: [[Double]]) -> [[Double]] {
    let rows = matrix.count
    let cols = matrix[0].count
    var result = Array(repeating: Array(repeating: 0.0, count: rows), count: cols)
    
    for i in 0..<rows {
        for j in 0..<cols {
            result[j][i] = matrix[i][j]
        }
    }
    return result
}

func addMatrices(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let rows = a.count
    let cols = a[0].count
    var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    
    for i in 0..<rows {
        for j in 0..<cols {
            result[i][j] = a[i][j] + b[i][j]
        }
    }
    return result
}

func printMatrix(_ matrix: [[Double]]) {
    for row in matrix {
        print(row.map { String(format: "%.1f", $0) }.joined(separator: " "))
    }
}

func main() {
    let a = [[1.0, 2.0], [3.0, 4.0]]
    let b = [[2.0, 0.0], [1.0, 2.0]]
    let result = processMatrix(a, b)
    printMatrix(result)
}

main()