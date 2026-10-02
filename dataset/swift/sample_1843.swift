import Foundation

func matrix_operations(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let x = matrixMultiply(a, b)
    let y = matrixAdd(x, transpose(b))
    let z = matrixSubtract(y, matrixMultiply(a, a))
    return z
}

func matrixMultiply(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    var result = Array(repeating: Array(repeating: 0.0, count: b[0].count), count: a.count)
    for i in 0..<a.count {
        for j in 0..<b[0].count {
            for k in 0..<b.count {
                result[i][j] += a[i][k] * b[k][j]
            }
        }
    }
    return result
}

func transpose(_ matrix: [[Double]]) -> [[Double]] {
    var result = Array(repeating: Array(repeating: 0.0, count: matrix.count), count: matrix[0].count)
    for i in 0..<matrix.count {
        for j in 0..<matrix[0].count {
            result[j][i] = matrix[i][j]
        }
    }
    return result
}

func matrixAdd(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    var result = Array(repeating: Array(repeating: 0.0, count: a[0].count), count: a.count)
    for i in 0..<a.count {
        for j in 0..<a[0].count {
            result[i][j] = a[i][j] + b[i][j]
        }
    }
    return result
}

func matrixSubtract(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    var result = Array(repeating: Array(repeating: 0.0, count: a[0].count), count: a.count)
    for i in 0..<a.count {
        for j in 0..<a[0].count {
            result[i][j] = a[i][j] - b[i][j]
        }
    }
    return result
}

func main() {
    let a = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
    let b = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
    let result = matrix_operations(a, b)
    for row in result {
        print(row)
    }
}

main()