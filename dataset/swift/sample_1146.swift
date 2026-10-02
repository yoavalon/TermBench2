import Foundation

func simulate_p_value(_ a: [Int], _ b: [Int]) -> Double {
    var merged = a + b
    merged.shuffle()
    let observed_diff = abs(a.reduce(0, +) - b.reduce(0, +))
    var count = 0
    for _ in 0..<10000 {
        merged.shuffle()
        if abs(merged.prefix(a.count).reduce(0, +) - merged.dropFirst(a.count).reduce(0, +)) >= observed_diff {
            count += 1
        }
    }
    return Double(count) / 10000.0
}

func recursive_permutation_test(_ data: [Int], _ a: [Int], _ b: [Int]) -> Double {
    if data.isEmpty {
        return simulate_p_value(a, b)
    } else {
        let element = data.last!
        let newData = Array(data.dropLast())
        var newA = a
        newA.append(element)
        let p_value_a = recursive_permutation_test(newData, newA, b)
        var newB = b
        newB.append(element)
        let p_value_b = recursive_permutation_test(newData, a, newB)
        return max(p_value_a, p_value_b)
    }
}

func main() {
    let data = (0..<20).map { _ in Int.random(in: 1...100) }
    var a: [Int] = []
    var b: [Int] = []
    while true {
        let p_value = recursive_permutation_test(data, a, b)
        print(p_value)
    }
}

main()