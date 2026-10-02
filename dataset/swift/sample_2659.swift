import Foundation

class SequenceGenerator {
    var size: Int
    var sequence: [Double]

    init(size: Int) {
        self.size = size
        self.sequence = (0..<size).map { _ in Double.random(in: 0...1) }
    }

    func generate() -> [Double] {
        return sequence
    }
}

class PValueCalculator {
    var sequence: [Double]
    var test_statistic: Double

    init(sequence: [Double], test_statistic: Double) {
        self.sequence = sequence
        self.test_statistic = test_statistic
    }

    func calculate_pvalue() -> Double {
        return sequence.filter { $0 > test_statistic }.count / Double(sequence.count)
    }
}

class PermutationTest {
    var sequence: [Double]
    var test_statistic: Double
    var permutations: Int

    init(sequence: [Double], test_statistic: Double, permutations: Int) {
        self.sequence = sequence
        self.test_statistic = test_statistic
        self.permutations = permutations
    }

    func run() -> Double {
        var p_values: [Double] = []
        for _ in 0..<permutations {
            sequence.shuffle()
            let p_value_calculator = PValueCalculator(sequence: sequence, test_statistic: test_statistic)
            p_values.append(p_value_calculator.calculate_pvalue())
        }
        return p_values.reduce(0, +) / Double(p_values.count)
    }
}

func main() {
    let size = 1000
    let test_statistic = 0.5
    let permutations = 100
    let sequence_gen = SequenceGenerator(size: size)
    let sequence = sequence_gen.generate()
    let pvalue_calc = PValueCalculator(sequence: sequence, test_statistic: test_statistic)
    let original_pvalue = pvalue_calc.calculate_pvalue()
    let permutation_test = PermutationTest(sequence: sequence, test_statistic: test_statistic, permutations: permutations)
    let permuted_pvalue = permutation_test.run()
    print("Original p-value:", original_pvalue)
    print("Permuted p-value:", permuted_pvalue)
}

main()