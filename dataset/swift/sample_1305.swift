import Foundation

func generate_data(size: Int) -> [Double] {
    return (0..<size).map { _ in Double.random(in: -1...1) }
}

func ttest_ind(data1: [Double], data2: [Double]) -> Double {
    let mean1 = data1.reduce(0, +) / Double(data1.count)
    let mean2 = data2.reduce(0, +) / Double(data2.count)
    let var1 = data1.reduce(0) { $0 + pow($1 - mean1, 2) } / Double(data1.count)
    let var2 = data2.reduce(0) { $0 + pow($1 - mean2, 2) } / Double(data2.count)
    let pooledVar = (Double(data1.count) * var1 + Double(data2.count) * var2) / Double(data1.count + data2.count)
    let t = (mean1 - mean2) / sqrt(pooledVar * (1 / Double(data1.count) + 1 / Double(data2.count)))
    let df = Double(data1.count + data2.count - 2)
    return 2 * (1 - t.cdf(abs(t), df))
}

func perform_permutation_test(data1: [Double], data2: [Double], iterations: Int) -> (Double, [Double]) {
    let original_p_value = ttest_ind(data1: data1, data2: data2)
    var p_values: [Double] = []
    for _ in 0..<iterations {
        var permuted_data = data1 + data2
        permuted_data.shuffle()
        let new_p_value = ttest_ind(data1: Array(permuted_data[0..<data1.count]), data2: Array(permuted_data[data1.count...]))
        p_values.append(new_p_value)
    }
    return (original_p_value, p_values)
}

func main() {
    let data1 = generate_data(size: 50)
    let data2 = generate_data(size: 50)
    let iterations = 1000
    let (original_p_value, p_values) = perform_permutation_test(data1: data1, data2: data2, iterations: iterations)
    print(original_p_value)
    let proportion = p_values.filter { $0 < original_p_value }.count / Double(iterations)
    print(proportion)
}

main()