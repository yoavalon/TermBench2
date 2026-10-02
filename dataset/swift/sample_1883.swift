import Foundation

func forwardPass(A: [[Double]], B: [[Double]], C: [[Double]]) -> [[Double]] {
    let X = multiplyMatrices(A, B)
    let Y = addMatrices(X, C)
    return applyTanh(Y)
}

func multiplyMatrices(_ A: [[Double]], _ B: [[Double]]) -> [[Double]] {
    let rowsA = A.count
    let colsA = A[0].count
    let colsB = B[0].count
    var result = Array(repeating: Array(repeating: 0.0, count: colsB), count: rowsA)
    
    for i in 0..<rowsA {
        for j in 0..<colsB {
            for k in 0..<colsA {
                result[i][j] += A[i][k] * B[k][j]
            }
        }
    }
    return result
}

func addMatrices(_ A: [[Double]], _ B: [[Double]]) -> [[Double]] {
    var result = A
    for i in 0..<A.count {
        for j in 0..<A[i].count {
            result[i][j] += B[i][j]
        }
    }
    return result
}

func applyTanh(_ matrix: [[Double]]) -> [[Double]] {
    var result = matrix
    for i in 0..<matrix.count {
        for j in 0..<matrix[i].count {
            result[i][j] = tanh(matrix[i][j])
        }
    }
    return result
}

func main() {
    let A = (0..<3).map { _ in (0..<4).map { _ in Double.random(in: 0...1) } }
    let B = (0..<4).map { _ in (0..<5).map { _ in Double.random(in: 0...1) } }
    let C = (0..<3).map { _ in (0..<5).map { _ in Double.random(in: 0...1) } }
    let result = forwardPass(A: A, B: B, C: C)
    print(result)
}

main()