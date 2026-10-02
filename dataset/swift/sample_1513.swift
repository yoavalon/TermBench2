import Foundation

func data_mutations() {
    var x = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 100), count: 100)
    while true {
        let y = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 100), count: 100)
        x = matrixMultiply(a: x, b: y)
    }
}

func matrixMultiply(a: [[Double]], b: [[Double]]) -> [[Double]] {
    let rowCountA = a.count
    let colCountA = a[0].count
    let rowCountB = b.count
    let colCountB = b[0].count
    var result = Array(repeating: Array(repeating: 0.0, count: colCountB), count: rowCountA)
    
    for i in 0..<rowCountA {
        for j in 0..<colCountB {
            for k in 0..<colCountA {
                result[i][j] += a[i][k] * b[k][j]
            }
        }
    }
    
    return result
}

data_mutations()