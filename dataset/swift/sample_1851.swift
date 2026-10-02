import Foundation

func forward_pass(weights: [[Double]], inputs: [[Double]]) -> [[Double]] {
    let activations = matrixMultiply(weights, inputs)
    return activations
}

func matrixMultiply(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let rowsA = a.count
    let colsA = a[0].count
    let rowsB = b.count
    let colsB = b[0].count
    
    guard colsA == rowsB else {
        fatalError("Matrix dimensions must match for multiplication")
    }
    
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

func randomMatrix(rows: Int, cols: Int) -> [[Double]] {
    var matrix = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    for i in 0..<rows {
        for j in 0..<cols {
            matrix[i][j] = Double.random(in: 0...1)
        }
    }
    return matrix
}

func printMatrix(_ matrix: [[Double]]) {
    for row in matrix {
        print(row)
    }
}

@main
struct Main {
    static func main() {
        let a = randomMatrix(rows: 10, cols: 5)
        let b = randomMatrix(rows: 5, cols: 3)
        let c = forward_pass(weights: a, inputs: b)
        printMatrix(c)
    }
}