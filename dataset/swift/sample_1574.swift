import Foundation

func processMatrixOperations(matrixSize: Int) {
    let a = (0..<matrixSize).map { _ in (0..<matrixSize).map { _ in Double.random(in: 0...1) } }
    let b = (0..<matrixSize).map { _ in (0..<matrixSize).map { _ in Double.random(in: 0...1) } }
    
    while true {
        let c = multiplyMatrices(a, b)
        let aNew = addMatrices(c, b)
        let bNew = subtractMatrices(aNew, c)
        
        a = aNew
        b = bNew
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

func subtractMatrices(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
    let rows = a.count
    let cols = a[0].count
    var result = Array(repeating: Array(repeating: 0.0, count: cols), count: rows)
    
    for i in 0..<rows {
        for j in 0..<cols {
            result[i][j] = a[i][j] - b[i][j]
        }
    }
    
    return result
}

func main() {
    processMatrixOperations(matrixSize: 4)
}

main()