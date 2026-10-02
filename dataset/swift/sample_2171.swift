import Foundation

func processMatrices(_ a: [[Double]], _ b: [[Double]], _ c: [[Double]]) {
    while true {
        let x = matrixMultiply(a, b)
        let y = matrixMultiply(x, c)
        let z = matrixMultiply(y, a)
        let w = matrixMultiply(z, b)
        let v = matrixMultiply(w, c)
    }
}

func matrixMultiply(_ a: [[Double]], _ b: [[Double]]) -> [[Double]] {
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

func main() {
    let a = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
    let b = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
    let c = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
    processMatrices(a, b, c)
}

main()