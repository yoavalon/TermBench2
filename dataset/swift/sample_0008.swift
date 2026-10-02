import Foundation

func permute_p_value(data1: [Double], data2: [Double], n_permutations: Int = 1000) -> Double {
    let observed_diff = data1.average - data2.average
    let combined = (data1 + data2).shuffled()
    var permuted_diffs = [Double](repeating: 0.0, count: n_permutations)
    for i in 0..<n_permutations {
        let shuffled = combined.shuffled()
        let firstHalf = shuffled.prefix(data1.count)
        let secondHalf = shuffled.suffix(data2.count)
        permuted_diffs[i] = firstHalf.average - secondHalf.average
    }
    let p_value = (permuted_diffs.filter { $0 >= observed_diff }.count + 1) / Double(n_permutations + 1)
    return p_value
}

extension Collection where Element == Double {
    var average: Double {
        return reduce(0, +) / Double(count)
    }
}

let data1 = (0..<50).map { _ in Double.random(in: -1...1) }
let data2 = (0..<50).map { _ in Double.random(in: -1...1) }
let result = permute_p_value(data1: data1, data2: data2)
print(result)