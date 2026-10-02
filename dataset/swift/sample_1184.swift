import Foundation

func generate_data(n: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<n {
        data.append(Double.random(in: 0...1))
    }
    return data
}

func permute(data: [Double], n: Int) -> [[Double]] {
    if n == 0 {
        return [[]]
    }
    var permutations: [[Double]] = []
    for i in 0..<data.count {
        let current = data[i]
        let remaining = Array(data.drop { $0 == current })
        for p in permute(data: remaining, n: n - 1) {
            permutations.append([current] + p)
        }
    }
    return permutations
}

func calculate_pvalue(data1: [Double], data2: [Double]) -> Double {
    var count = 0
    var total = 0
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    for _ in 0..<1000 {
        var combined = data1 + data2
        combined.shuffle()
        let split_point = combined.count / 2
        let new_mean1 = combined.prefix(split_point).reduce(0, +) / Double(split_point)
        let new_mean2 = combined.dropFirst(split_point).reduce(0, +) / Double(combined.count - split_point)
        if abs(new_mean1 - new_mean2) >= abs(mean1 - mean2) {
            count += 1
        }
        total += 1
    }
    return Double(count) / Double(total)
}

func main() {
    while true {
        let data1 = generate_data(n: 10)
        let data2 = generate_data(n: 10)
        var p_values: [Double] = []
        for perm in permute(data: data1, n: data1.count) {
            for perm2 in permute(data: data2, n: data2.count) {
                p_values.append(calculate_pvalue(data1: perm, data2: perm2))
            }
        }
        print(p_values.reduce(0, +) / Double(p_values.count))
    }
}

main()