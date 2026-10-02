import Foundation

class PermutationGenerator {
    var data: [Int]
    var n_permutations: Int
    var permutations: [[Int]]

    init(data: [Int], n_permutations: Int) {
        self.data = data
        self.n_permutations = n_permutations
        self.permutations = []
        self.generate()
    }

    func generate() {
        if permutations.count < n_permutations {
            permutations.append(data.shuffled())
            generate()
        }
    }
}

class PValueCalculator {
    var original_data: [Int]
    var permuted_data: [[Int]]

    init(original_data: [Int], permuted_data: [[Int]]) {
        self.original_data = original_data
        self.permuted_data = permuted_data
    }

    func calculate() -> Double {
        let original_stat = calculate_statistic(data: original_data)
        let p_value = permuted_data.filter { calculate_statistic(data: $0) >= original_stat }.count / Double(permuted_data.count)
        return p_value
    }

    func calculate_statistic(data: [Int]) -> Int {
        return data.reduce(0, +)
    }
}

class TerminationAnalyzer {
    var data: [Int]
    var n_permutations: Int
    var permutation_generator: PermutationGenerator
    var p_value_calculator: PValueCalculator

    init(data: [Int], n_permutations: Int) {
        self.data = data
        self.n_permutations = n_permutations
        self.permutation_generator = PermutationGenerator(data: data, n_permutations: n_permutations)
        self.p_value_calculator = PValueCalculator(original_data: data, permuted_data: permutation_generator.permutations)
    }

    func analyze() -> Double {
        return p_value_calculator.calculate()
    }
}

func main() {
    let data = [1, 2, 3, 4, 5]
    let n_permutations = 1000
    let analyzer = TerminationAnalyzer(data: data, n_permutations: n_permutations)
    let result = analyzer.analyze()
    print(result)
}

main()