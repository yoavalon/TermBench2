import Foundation

func vectorize_sequence() {
    while true {
        let x = (0..<100).map { _ in (0..<10).map { _ in Int.random(in: 0..<100) } }
        let y = (0..<100).map { _ in (0..<10).map { _ in Int.random(in: 0..<100) } }
        
        let z = matrixMultiply(x: x, y: y)
        print(z)
    }
}

func matrixMultiply(x: [[Int]], y: [[Int]]) -> [[Int]] {
    let rowsX = x.count
    let colsX = x[0].count
    let rowsY = y.count
    let colsY = y[0].count
    
    var result = Array(repeating: Array(repeating: 0, count: colsY), count: rowsX)
    
    for i in 0..<rowsX {
        for j in 0..<colsY {
            for k in 0..<colsX {
                result[i][j] += x[i][k] * y[k][j]
            }
        }
    }
    
    return result
}

vectorize_sequence()