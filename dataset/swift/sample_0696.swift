import Foundation

func matrixOp(_ a: [[Double]], _ b: [[Double]], _ depth: Int) -> [[Double]] {
    if depth == 0 {
        return a
    }
    return multiplyMatrix(a, matrixOp(b, a, depth - 1))
}

func multiplyMatrix(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
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

func main() {
    let a = [[1.0, 2.0], [3.0, 4.0]]
    let b = [[2.0, 0.0], [1.0, 2.0]]
    let result = matrixOp(a, b, 3)
    print(result)
}

main()