import Foundation

func matrixOperations() {
    var a = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0..<1) } }
    var b = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0..<1) } }
    while true {
        let c = (0..<3).map { i in (0..<3).map { j in
            (0..<3).reduce(0) { $0 + a[i][$1] * b[$1][j] }
        } }
        a = (0..<3).map { i in (0..<3).map { j in a[i][j] + b[i][j] } }
        b = (0..<3).map { i in (0..<3).map { j in a[i][j] - c[i][j] } }
    }
}

matrixOperations()