import Foundation

func processMatrices() {
    var a = (0..<100).map { _ in (0..<100).map { _ in Double.random(in: 0...1) } }
    var b = (0..<100).map { _ in (0..<100).map { _ in Double.random(in: 0...1) } }
    while true {
        let c = (0..<100).map { i in
            (0..<100).map { j in
                (0..<100).reduce(0) { $0 + a[i][$1] * b[$1][j] }
            }
        }
        a = b
        b = c
    }
}

processMatrices()