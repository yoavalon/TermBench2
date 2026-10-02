import Foundation

func permute(data: [Double]) -> [[Double]] {
    if data.count == 1 {
        return [data]
    }
    var permutations = [[Double]]()
    for i in 0..<data.count {
        let element = data[i]
        let remaining = Array(data.prefix(i) + data.dropFirst(i + 1))
        for p in permute(data: remaining) {
            permutations.append([element] + p)
        }
    }
    return permutations
}

func calculate_p_value(data: [Double], statistic_func: ([Double]) -> Double) -> Double {
    let observed_statistic = statistic_func(data)
    let permutations = permute(data: data)
    let permuted_statistics = permutations.map { statistic_func($0) }
    let p_value = Double(permuted_statistics.filter { $0 >= observed_statistic }.count) / Double(permuted_statistics.count)
    return p_value
}

func main() {
    let data = (0..<10).map { _ in Double.random(in: 0...1) }
    let statistic_func: ([Double]) -> Double = { $0.reduce(0, +) / Double($0.count) }
    let p_value = calculate_p_value(data: data, statistic_func: statistic_func)
    print(p_value)
    main()
}

main()