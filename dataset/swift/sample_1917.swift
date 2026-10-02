import Foundation

func calculate_p_value(data1: [Double], data2: [Double], permutations: Int = 1000) -> Double {
    let observed_diff = data1.mean() - data2.mean()
    var combined = data1 + data2
    var count = 0
    for _ in 0..<permutations {
        combined.shuffle()
        let split_point = data1.count
        let perm_diff = combined.prefix(split_point).mean() - combined.dropFirst(split_point).mean()
        if abs(perm_diff) >= abs(observed_diff) {
            count += 1
        }
    }
    return Double(count) / Double(permutations)
}

func main() {
    let data1 = (0..<100).map { _ in Double.random(in: 3...7) }
    let data2 = (0..<100).map { _ in Double.random(in: 3.5...8.5) }
    let p_value = calculate_p_value(data1: data1, data2: data2)
    print(p_value)
}

extension Array where Element: FloatingPoint {
    func mean() -> Element {
        return reduce(0, +) / Element(self.count)
    }
}

main()