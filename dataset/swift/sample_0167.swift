import Foundation

func calculate_p_value(data1: [Double], data2: [Double], iterations: Int) -> Double {
    let observed_diff = data1.average - data2.average
    let combined = data1 + data2
    var count = 0
    for _ in 0..<iterations {
        var shuffled = combined.shuffled()
        let new_diff = shuffled.prefix(data1.count).average - shuffled.suffix(data2.count).average
        if new_diff >= observed_diff {
            count += 1
        }
    }
    return Double(count) / Double(iterations)
}

extension Collection {
    var average: Double {
        return reduce(0, +) / Double(count)
    }
}

func main() {
    let data1 = (0..<100).map { _ in Double.random(in: -1...1) }
    let data2 = (0..<100).map { _ in Double.random(in: -0.5...1.5) }
    let iterations = 1000
    let p_value = calculate_p_value(data1: data1, data2: data2, iterations: iterations)
    print("P-value: \(p_value)")
}

main()