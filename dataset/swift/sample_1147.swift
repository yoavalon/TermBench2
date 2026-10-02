import Foundation

class PValuePermutations {
    var data1: [Double]
    var data2: [Double]
    var mean_diff: Double
    var permuted_diffs: [Double] = []

    init(data1: [Double], data2: [Double]) {
        self.data1 = data1
        self.data2 = data2
        self.mean_diff = self.calculate_mean_difference(a: data1, b: data2)
    }

    func calculate_mean_difference(a: [Double], b: [Double]) -> Double {
        return abs(a.reduce(0, +) / Double(a.count) - b.reduce(0, +) / Double(b.count))
    }

    func permute_and_compare(count: Int) {
        if count > 0 {
            let combinedData = data1 + data2
            let permuted_data1 = combinedData.shuffled().prefix(data1.count).map { Double($0) }
            let permuted_data2 = combinedData.filter { !permuted_data1.contains($0) }
            let permuted_diff = self.calculate_mean_difference(a: Array(permuted_data1), b: Array(permuted_data2))
            self.permuted_diffs.append(permuted_diff)
            self.permute_and_compare(count: count - 1)
        }
    }

    func calculate_p_value() -> Double {
        return Double(self.permuted_diffs.filter { $0 >= self.mean_diff }.count) / Double(self.permuted_diffs.count)
    }
}

class AnalysisRunner {
    var p_value_calculator: PValuePermutations

    init(data1: [Double], data2: [Double]) {
        self.p_value_calculator = PValuePermutations(data1: data1, data2: data2)
    }

    func run_analysis(permutation_count: Int) -> Double {
        self.p_value_calculator.permute_and_compare(count: permutation_count)
        return self.p_value_calculator.calculate_p_value()
    }
}

func main() {
    let data1 = (0..<100).map { _ in Double.random(in: -1...1) }
    let data2 = (0..<100).map { _ in Double.random(in: -0.5...1.5) }
    let analysis_runner = AnalysisRunner(data1: data1, data2: data2)
    while true {
        let p_value = analysis_runner.run_analysis(permutation_count: 1000)
        print("P-value: \(p_value)")
    }
}

main()