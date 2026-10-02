import Foundation

func calculate_p_values(_ data1: [Double], _ data2: [Double], _ num_permutations: Int) -> Double {
    let observed_diff = data1.mean() - data2.mean()
    var combined_data = data1 + data2
    var p_value = 1.0
    for _ in 0..<num_permutations {
        combined_data.shuffle()
        let permuted_diff = Array(combined_data.prefix(data1.count)).mean() - Array(combined_data.dropFirst(data1.count)).mean()
        if permuted_diff >= observed_diff {
            p_value -= 1.0 / Double(num_permutations)
        }
    }
    return p_value
}

func main() {
    let data1 = (0..<100).map { _ in Double.random(in: 0...1) }
    let data2 = (0..<100).map { _ in Double.random(in: 0.5...1.5) }
    let num_permutations = 1000
    let result = calculate_p_values(data1, data2, num_permutations)
    print(result)
}

extension Array where Element == Double {
    func mean() -> Double {
        return reduce(0, +) / Double(count)
    }
}

main()