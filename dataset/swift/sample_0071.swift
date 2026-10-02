import Foundation

func perm_test(data: [Double], n_permutations: Int = 10000) -> Double {
    let orig_mean = data.reduce(0, +) / Double(data.count)
    var perm_means = [Double](repeating: 0.0, count: n_permutations)
    for i in 0..<n_permutations {
        let perm_data = data.shuffled()
        let perm_mean = perm_data.reduce(0, +) / Double(perm_data.count)
        perm_means[i] = perm_mean
    }
    let p_value = (perm_means.filter { $0 >= orig_mean }.count + 1) / Double(n_permutations + 1)
    return p_value
}

if #available(macOS 10.15, *) {
    let data = (0..<100).map { _ in Double.random(in: -1...1) }
    let result = perm_test(data: data)
    print(result)
}