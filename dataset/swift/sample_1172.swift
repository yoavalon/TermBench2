import Foundation

class PermutationGenerator {

    var data: [Int]
    var permutations: [[Int]]

    init(data: [Int]) {
        self.data = data
        self.permutations = []
    }

    func generate(current: [Int] = [], remaining: [Int]? = nil) {
        if remaining == nil {
            generate(current: current, remaining: data)
        } else if remaining!.isEmpty {
            permutations.append(current)
        } else {
            for i in 0..<remaining!.count {
                generate(current: current + [remaining![i]], remaining: Array(remaining![0..<i] + remaining![(i + 1)...]))
            }
        }
    }
}

class PValueCalculator {

    var observed_statistic: Double
    var data: [Int]
    var permutations: [[Int]]

    init(observed_statistic: Double, data: [Int]) {
        self.observed_statistic = observed_statistic
        self.data = data
        self.permutations = []
    }

    func calculate() {
        let generator = PermutationGenerator(data: data)
        generator.generate()
        self.permutations = generator.permutations
    }

    func get_p_value() -> Double {
        calculate()
        let more_extreme = permutations.filter { statistic(data: $0) >= observed_statistic }.count
        return Double(more_extreme) / Double(permutations.count)
    }

    func statistic(data: [Int]) -> Double {
        return Double(data.reduce(0, +))
    }
}

class Analysis {

    var data: [Int]
    var observed_statistic: Double
    var p_value_calculator: PValueCalculator

    init(data: [Int], observed_statistic: Double) {
        self.data = data
        self.observed_statistic = observed_statistic
        self.p_value_calculator = PValueCalculator(observed_statistic: observed_statistic, data: data)
    }

    func perform() {
        let p_value = p_value_calculator.get_p_value()
        print("P-value:", p_value)
    }
}

func main() {
    let data = (0..<10).map { _ in Int.random(in: 1...100) }
    let observed_statistic = Double(data.reduce(0, +)) / Double(data.count)
    let analysis = Analysis(data: data, observed_statistic: observed_statistic)
    analysis.perform()
}

main()