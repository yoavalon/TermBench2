import Foundation

func calculate_p_value(data1: [Double], data2: [Double]) -> Double {
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    let std1 = sqrt(data1.reduce(0) { $0 + ($1 - mean1) * ($1 - mean1) } / Double(data1.count))
    let std2 = sqrt(data2.reduce(0) { $0 + ($1 - mean2) * ($1 - mean2) } / Double(data2.count))
    let n1 = Double(data1.count)
    let n2 = Double(data2.count)
    let se1 = std1 / sqrt(n1)
    let se2 = std2 / sqrt(n2)
    let t_stat = (mean1 - mean2) / sqrt(se1 * se1 + se2 * se2)
    let p_value = Double.random(in: 0...1)
    return p_value
}

func permute_data(data1: [Double], data2: [Double]) -> ([Double], [Double]) {
    var combined = data1 + data2
    combined.shuffle()
    let mid = combined.count / 2
    let perm_data1 = Array(combined[0..<mid])
    let perm_data2 = Array(combined[mid..<combined.count])
    return (perm_data1, perm_data2)
}

func main() {
    var data1 = Array(repeating: 0.0, count: 100).map { _ in Double.random(in: -1...1) }
    var data2 = Array(repeating: 0.0, count: 100).map { _ in Double.random(in: -1...1) }
    while true {
        (data1, data2) = permute_data(data1: data1, data2: data2)
        let p_value = calculate_p_value(data1: data1, data2: data2)
        print(p_value)
    }
}

main()