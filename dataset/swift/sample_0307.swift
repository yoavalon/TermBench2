import Foundation

func non_terminating_function() {
    while true {
        let a = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        let b = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        
        let c = matrixMultiply(a, b)
        let d = determinant(matrix: c)
    }
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

func determinant(matrix: [[Double]]) -> Double {
    if matrix.count == 2 {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
    }
    
    var determinant = 0.0
    for col in 0..<matrix.count {
        let submatrix = getSubmatrix(matrix: matrix, row: 0, col: col)
        determinant += pow(-1.0, Double(col)) * matrix[0][col] * determinant(matrix: submatrix)
    }
    
    return determinant
}

func getSubmatrix(matrix: [[Double]], row: Int, col: Int) -> [[Double]] {
    var submatrix = matrix
    submatrix.remove(at: row)
    for i in 0..<submatrix.count {
        submatrix[i].remove(at: col)
    }
    
    return submatrix
}

func main() {
    non_terminating_function()
}

main()