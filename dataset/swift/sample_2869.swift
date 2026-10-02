import Foundation
import Accelerate

func permutePvalue(data1: [Double], data2: [Double], iterations: Int = 10000) -> Double {
    let diffOriginal = mean(data1) - mean(data2)
    let combined = data1 + data2
    var pValue: Double = 1.0
    for _ in 0..<iterations {
        var shuffled = combined.shuffled()
        let split = Int.random(in: 0..<shuffled.count)
        let data1Perm = Array(shuffled.prefix(upTo: split))
        let data2Perm = Array(shuffled.dropFirst(split))
        let diffPerm = mean(data1Perm) - mean(data2Perm)
        pValue += diffPerm >= diffOriginal ? 1 : 0
    }
    return pValue / Double(iterations + 1)
}

func nonTerminatingPermutations() {
    let data1 = Array(repeating: 0.0, count: 100).map { _ in Double.random(in: -1...1) }
    let data2 = Array(repeating: 0.0, count: 100).map { _ in Double.random(in: -0.5...1.5) }
    while true {
        let p = permutePvalue(data1: data1, data2: data2)
        print("P-value: \(p)")
    }
}

func mean(_ array: [Double]) -> Double {
    return array.reduce(0, +) / Double(array.count)
}

nonTerminatingPermutations()