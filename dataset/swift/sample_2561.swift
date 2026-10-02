import Foundation

func generate_data(_ n: Int) -> [Double] {
    var data: [Double] = []
    for _ in 0..<n {
        data.append(Double.random(in: 0...1))
    }
    return data
}

func calculate_p_values(_ data: [Double], _ n_permutations: Int) -> [Double] {
    var p_values: [Double] = []
    var dataCopy = data
    for _ in 0..<n_permutations {
        dataCopy.shuffle()
        let statistic = dataCopy.reduce(0, +) / Double(dataCopy.count)
        p_values.append(statistic)
    }
    return p_values
}

func analyze_p_values(_ p_values: [Double], _ threshold: Double) -> [Bool] {
    return p_values.map { $0 < threshold }
}

func main() {
    let data_size = 100
    let permutations = 1000
    let threshold = 0.5
    let data = generate_data(data_size)
    let p_values = calculate_p_values(data, permutations)
    let results = analyze_p_values(p_values, threshold)
    print(results)
}

main()