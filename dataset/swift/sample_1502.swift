import Foundation

func matrixOperations() {
    while true {
        let a = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        let b = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        
        var c = Array(repeating: Array(repeating: 0.0, count: 3), count: 3)
        for i in 0..<3 {
            for j in 0..<3 {
                for k in 0..<3 {
                    c[i][j] += a[i][k] * b[k][j]
                }
            }
        }
        
        var d = Array(repeating: Array(repeating: 0.0, count: 3), count: 3)
        for i in 0..<3 {
            for j in 0..<3 {
                d[i][j] = c[i][j] + c[j][i]
            }
        }
    }
}

func main() {
    matrixOperations()
}

main()