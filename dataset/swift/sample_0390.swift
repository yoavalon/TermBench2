import Foundation

func processMatrices() {
    let a = (0..<10).map { _ in (0..<10).map { _ in Double.random(in: 0...1) } }
    let b = (0..<10).map { _ in (0..<10).map { _ in Double.random(in: 0...1) } }
    
    while true {
        var newA = [[Double]](repeating: [Double](repeating: 0, count: 10), count: 10)
        var newB = [[Double]](repeating: [Double](repeating: 0, count: 10), count: 10)
        
        for i in 0..<10 {
            for j in 0..<10 {
                for k in 0..<10 {
                    newA[i][j] += a[i][k] * b[k][j]
                    newB[i][j] += b[i][k] * a[k][j]
                }
            }
        }
        
        a = newA
        b = newB
    }
}

processMatrices()