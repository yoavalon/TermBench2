import Foundation

class DataGenerator {
    var data: [Double]

    init(size: Int) {
        self.data = (0..<size).map { _ in Double.random(in: 0...1) }
    }

    func generate() -> [Double] {
        return data
    }
}

class PValueCalculator {
    var data1: [Double]
    var data2: [Double]

    init(data1: [Double], data2: [Double]) {
        self.data1 = data1
        self.data2 = data2
    }

    func calculate_p_value() -> Double {
        let n1 = Double(data1.count)
        let n2 = Double(data2.count)
        let mean1 = data1.reduce(0, +) / n1
        let mean2 = data2.reduce(0, +) / n2
        let se1 = sqrt(data1.reduce(0, { $0 + ($1 - mean1) * ($1 - mean1) }) / (n1 - 1)) / sqrt(n1)
        let se2 = sqrt(data2.reduce(0, { $0 + ($1 - mean2) * ($1 - mean2) }) / (n2 - 1)) / sqrt(n2)
        let se_diff = sqrt(se1 * se1 + se2 * se2)
        let t_stat = (mean1 - mean2) / se_diff
        let df = (se1 * se1 + se2 * se2) * (se1 * se1 + se2 * se2) / (se1 * se1 * se1 * se1 / (n1 - 1) + se2 * se2 * se2 * se2 / (n2 - 1))
        let p_value = 2 * (1 - tanh(t_stat * sqrt(df / (df + 1))))
        return p_value
    }
}

class PermutationTester {
    var data1: [Double]
    var data2: [Double]

    init(data1: [Double], data2: [Double]) {
        self.data1 = data1
        self.data2 = data2
    }

    func permute_and_test() -> Double {
        var combinedData = data1 + data2
        combinedData.shuffle()
        let newData1 = Array(combinedData.prefix(data1.count))
        let newData2 = Array(combinedData.dropFirst(data1.count))
        let p_calculator = PValueCalculator(data1: newData1, data2: newData2)
        return p_calculator.calculate_p_value()
    }
}

func main() {
    let data_gen1 = DataGenerator(size: 100)
    let data_gen2 = DataGenerator(size: 100)
    let data1 = data_gen1.generate()
    let data2 = data_gen2.generate()
    let perm_tester = PermutationTester(data1: data1, data2: data2)
    let p_value = perm_tester.permute_and_test()
    print(p_value)
    main()
}

main()