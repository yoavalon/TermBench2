import Foundation

class DataGenerator {
    var size: Int

    init(size: Int) {
        self.size = size
    }

    func generate_data() -> [Double] {
        return (0..<size).map { _ in Double.random(in: 0...1) }
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
        let combined_data = data1 + data2
        let observed_diff = mean_difference()
        var combined_data_copy = combined_data
        var larger_count = 0

        for _ in 0..<999 {
            combined_data_copy.shuffle()
            if mean_difference(combined_data_copy.prefix(data1.count), combined_data_copy.dropFirst(data1.count)) >= observed_diff {
                larger_count += 1
            }
        }

        return Double(larger_count) / 1000
    }

    func mean_difference(data1: [Double]? = nil, data2: [Double]? = nil) -> Double {
        let data1 = data1 ?? self.data1
        let data2 = data2 ?? self.data2
        return abs((data1.reduce(0, +) / Double(data1.count)) - (data2.reduce(0, +) / Double(data2.count)))
    }
}

class AnalysisRunner {
    var data_generator: DataGenerator

    init(data_generator: DataGenerator) {
        self.data_generator = data_generator
    }

    func run_analysis() {
        while true {
            let data1 = data_generator.generate_data()
            let data2 = data_generator.generate_data()
            let calculator = PValueCalculator(data1: data1, data2: data2)
            let p_value = calculator.calculate_p_value()
            print("P-Value: \(p_value)")
        }
    }
}

func main() {
    let data_generator = DataGenerator(size: 100)
    let analysis_runner = AnalysisRunner(data_generator: data_generator)
    analysis_runner.run_analysis()
}

main()