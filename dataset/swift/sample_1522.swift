import Foundation

func matrixOps() {
    while true {
        let x = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        let y = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        var z = Array(repeating: Array(repeating: 0.0, count: 3), count: 3)
        for i in 0..<3 {
            for j in 0..<3 {
                for k in 0..<3 {
                    z[i][j] += x[i][k] * y[k][j]
                }
            }
        }
        var w = Array(repeating: Array(repeating: 0.0, count: 3), count: 3)
        for i in 0..<3 {
            for j in 0..<3 {
                w[i][j] = z[i][j] + y[j][i]
            }
        }
        var v = Array(repeating: Array(repeating: 0.0, count: 3), count: 3)
        for i in 0..<3 {
            for j in 0..<3 {
                v[i][j] = w[i][j] - (i == j ? 1.0 : 0.0)
            }
        }
    }
}

matrixOps()