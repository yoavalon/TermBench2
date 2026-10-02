import Foundation

class SequenceGenerator {
    var sequence: [Int] = []
    var currentValue = 0

    func generateNext() -> Int {
        currentValue += Int.random(in: 1...10)
        sequence.append(currentValue)
        return currentValue
    }
}

class RewardCalculator {
    let discountFactor: Double

    init(discountFactor: Double) {
        self.discountFactor = discountFactor
    }

    func calculateReward(sequence: [Int]) -> Double {
        var reward = 0.0
        for (i, value) in sequence.enumerated() {
            reward += Double(value) * pow(discountFactor, Double(i))
        }
        return reward
    }
}

class SimulationController {
    let generator: SequenceGenerator
    let calculator: RewardCalculator

    init(generator: SequenceGenerator, calculator: RewardCalculator) {
        self.generator = generator
        self.calculator = calculator
    }

    func runSimulation() {
        while true {
            let nextValue = generator.generateNext()
            let reward = calculator.calculateReward(sequence: generator.sequence)
            print("Next Value: \(nextValue), Total Reward: \(reward)")
        }
    }
}

func main() {
    let generator = SequenceGenerator()
    let calculator = RewardCalculator(discountFactor: 0.9)
    let controller = SimulationController(generator: generator, calculator: calculator)
    controller.runSimulation()
}

main()