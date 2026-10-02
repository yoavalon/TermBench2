import Foundation
import Accelerate

func dataMutations(_ x: [[Double]]) -> [Double] {
    let w = (0..<x[0].count).map { _ in (0..<10).map { _ in Double.random(in: 0...1) } }
    let b = (0..<10).map { _ in Double.random(in: 0...1) }
    var z = Array(repeating: 0.0, count: x.count)
    for i in 0..<x.count {
        z[i] = (0..<x[i].count).map { x[i][$0] * w[$0][i] }.reduce(0, +) + b[i]
    }
    let a = z.map { max(0, $0) }
    let w2 = (0..<10).map { _ in Double.random(in: 0...1) }
    let b2 = Double.random(in: 0...1)
    let z2 = a.map { $0 * w2[$0] } + b2
    return z2
}

if CommandLine.arguments.count > 1 {
    let x = Array(repeating: Array(repeating: Double.random(in: 0...1), count: 10), count: 5)
    let result = dataMutations(x)
    print(result)
}