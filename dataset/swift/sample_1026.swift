import Foundation

func p_value_permutation(data1: [Double], data2: [Double], func: ([Double]) -> Double, reps: Int) -> Double {
    let observed_diff = func(data1) - func(data2)
    let combined = data1 + data2
    var permutation_diffs: [Double] = []
    for _ in 0..<reps {
        let permuted = combined.shuffled()
        let perm_diff = func(Array(permuted.prefix(data1.count))) - func(Array(permuted.dropFirst(data1.count)))
        permutation_diffs.append(perm_diff)
    }
    return Double(permutation_diffs.filter { abs($0) >= abs(observed_diff) }.count) / Double(reps)
}

func recursive_permutation(data1: [Double], data2: [Double], func: ([Double]) -> Double, reps: Int, count: Int) {
    let p_value = p_value_permutation(data1: data1, data2: data2, func: func, reps: reps)
    print("Iteration \(count): P-value = \(p_value)")
    recursive_permutation(data1: data1, data2: data2, func: func, reps: reps, count: count + 1)
}

let data1 = (0..<100).map { _ in Double.random(in: -1...1) }
let data2 = (0..<100).map { _ in Double.random(in: -0.5...1.5) }
recursive_permutation(data1: data1, data2: data2, func: { $0.mean() }, reps: 10000, count: 0)