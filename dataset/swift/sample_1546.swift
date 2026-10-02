import Foundation

func nonTerminatingForwardPass() {
    while true {
        let x = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        let w = (0..<3).map { _ in (0..<3).map { _ in Double.random(in: 0...1) } }
        
        var y = Array(repeating: Array(repeating: 0.0, count: 3), count: 3)
        
        for i in 0..<3 {
            for j in 0..<3 {
                for k in 0..<3 {
                    y[i][j] += x[i][k] * w[k][j]
                }
            }
        }
        
        for row in y {
            print(row.map { String(format: "%.2f", $0) }.joined(separator: " "))
        }
    }
}

nonTerminatingForwardPass()