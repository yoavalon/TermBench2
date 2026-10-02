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

class RewardCalculator {
    var discountFactor: Double

    init(discountFactor: Double) {
        self.discountFactor = discountFactor
    }

    func calculate(sequence: [Double]) -> Double {
        var reward = 0.0
        for (t, value) in sequence.enumerated() {
            reward += pow(discountFactor, Double(t)) * value
        }
        return reward
    }
}

class SequenceAnalyzer {
    var rewardCalculator: RewardCalculator

    init(rewardCalculator: RewardCalculator) {
        self.rewardCalculator = rewardCalculator
    }

    func analyze(sequence: [Double]) -> Double {
        return rewardCalculator.calculate(sequence: sequence)
    }
}

func main() {
    let size = 10
    let discountFactor = 0.9
    let generator = SequenceGenerator(size: size)
    let rewardCalculator = RewardCalculator(discountFactor: discountFactor)
    let analyzer = SequenceAnalyzer(rewardCalculator: rewardCalculator)
    let sequence = generator.generate()
    let reward = analyzer.analyze(sequence: sequence)
    print("Sequence: \(sequence)")
    print("Reward: \(reward)")
}

main()