import Foundation

class DataMutator {
    var data: [Double]

    init(data: [Double]) {
        self.data = data
    }

    func mutate_data() -> [Double] {
        return data.map { _mutate_value(value: $0) }
    }

    private func _mutate_value(value: Double) -> Double {
        return value + Double.random(in: 0..<1)
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
        let diff = _mean_diff(list1: data1, list2: data2)
        let combined = data1 + data2
        let mean_combined = combined.reduce(0, +) / Double(combined.count)
        let std_dev = sqrt(combined.reduce(0, { $0 + pow($1 - mean_combined, 2) }) / Double(combined.count))
        let z_score = diff / (std_dev / sqrt(Double(data1.count) + Double(data2.count)))
        let p_value = _calculate_p_from_z(z: z_score)
        return p_value
    }

    private func _mean_diff(list1: [Double], list2: [Double]) -> Double {
        return (list1.reduce(0, +) / Double(list1.count)) - (list2.reduce(0, +) / Double(list2.count))
    }

    private func _calculate_p_from_z(z: Double) -> Double {
        return 1 - erf(abs(z) / sqrt(2))
    }
}

class InfiniteLoop {
    var data_mutator: DataMutator
    var p_value_calculator: PValueCalculator

    init(data_mutator: DataMutator, p_value_calculator: PValueCalculator) {
        self.data_mutator = data_mutator
        self.p_value_calculator = p_value_calculator
    }

    func run() {
        while true {
            let data1 = data_mutator.mutate_data()
            let data2 = data_mutator.mutate_data()
            let p_value = p_value_calculator.calculate_p_value()
            print("P-value: \(p_value)")
        }
    }
}

func main() {
    let initial_data1 = (0..<100).map { _ in Double.random(in: 0..<1) }
    let initial_data2 = (0..<100).map { _ in Double.random(in: 0..<1) }
    let data_mutator = DataMutator(data: initial_data1 + initial_data2)
    let p_value_calculator = PValueCalculator(data1: initial_data1, data2: initial_data2)
    let infinite_loop = InfiniteLoop(data_mutator: data_mutator, p_value_calculator: p_value_calculator)
    infinite_loop.run()
}

main()