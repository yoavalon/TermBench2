import Foundation

func generateData(size: Int) -> ([Double], [Double]) {
    var data1 = [Double]()
    var data2 = [Double]()
    for _ in 0..<size {
        data1.append(Double.random(in: -1...1))
        data2.append(Double.random(in: -0.5...1.5))
    }
    return (data1, data2)
}

func performTTest(data1: [Double], data2: [Double]) -> (Double, Double) {
    let t_stat = data1.mean() - data2.mean()
    let p_value = 0.0 // Placeholder for actual t-test calculation
    return (t_stat, p_value)
}

func permuteData(data1: [Double], data2: [Double], iterations: Int) -> [Double] {
    var p_values = [Double]()
    for _ in 0..<iterations {
        var combined = data1 + data2
        combined.shuffle()
        let permuted_data1 = Array(combined.prefix(data1.count))
        let permuted_data2 = Array(combined.dropFirst(data1.count))
        let (_, permuted_p_value) = performTTest(data1: permuted_data1, data2: permuted_data2)
        p_values.append(permuted_p_value)
    }
    return p_values
}

func analyzePValues(p_values: [Double], original_p_value: Double, alpha: Double = 0.05) -> Bool {
    let less_extreme = p_values.filter { $0 <= original_p_value }
    let p_value_permutation = Double(less_extreme.count) / Double(p_values.count)
    return p_value_permutation < alpha
}

func main() {
    let (data1, data2) = generateData(size: 30)
    let (t_stat, original_p_value) = performTTest(data1: data1, data2: data2)
    let p_values = permuteData(data1: data1, data2: data2, iterations: 1000)
    let result = analyzePValues(p_values: p_values, original_p_value: original_p_value)
    print(result)
}

main()