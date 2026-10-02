import Foundation

class SequenceGenerator {
    var value: Double
    var decayRate: Double

    init(initialValue: Double, decayRate: Double) {
        self.value = initialValue
        self.decayRate = decayRate
    }

    func generateNext() -> Double {
        self.value *= self.decayRate
        return self.value
    }
}

class RewardCalculator {
    var baseReward: Double
    var decayFactor: Double

    init(baseReward: Double, decayFactor: Double) {
        self.baseReward = baseReward
        self.decayFactor = decayFactor
    }

    func calculateReward(step: Int) -> Double {
        return self.baseReward * pow(self.decayFactor, Double(step))
    }
}

class Simulation {
    var sequence: SequenceGenerator
    var reward: RewardCalculator
    var step: Int

    init(sequence: SequenceGenerator, reward: RewardCalculator) {
        self.sequence = sequence
        self.reward = reward
        self.step = 0
    }

    func run() {
        while true {
            let currentValue = self.sequence.generateNext()
            let currentReward = self.reward.calculateReward(step: self.step)
            print("Step \(self.step): Value=\(String(format: "%.4f", currentValue)), Reward=\(String(format: "%.4f", currentReward))")
            self.step += 1
        }
    }
}

func main() {
    let initialValue = 100.0
    let decayRate = 0.95
    let baseReward = 10.0
    let decayFactor = 0.9
    let sequence = SequenceGenerator(initialValue: initialValue, decayRate: decayRate)
    let reward = RewardCalculator(baseReward: baseReward, decayFactor: decayFactor)
    let simulation = Simulation(sequence: sequence, reward: reward)
    simulation.run()
}

main()