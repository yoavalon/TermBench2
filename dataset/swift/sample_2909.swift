class SequenceGenerator {
    var base: Int
    var increment: Int
    var current: Int

    init(base: Int, increment: Int) {
        self.base = base
        self.increment = increment
        self.current = base
    }

    func nextValue() -> Int {
        self.current += self.increment
        return self.current
    }
}

class RewardCalculator {
    var currentReward: Double
    var decayRate: Double

    init(initialReward: Double, decayRate: Double) {
        self.currentReward = initialReward
        self.decayRate = decayRate
    }

    func calculate() -> Double {
        self.currentReward *= self.decayRate
        return self.currentReward
    }
}

class Environment {
    var sequence: SequenceGenerator
    var reward: RewardCalculator

    init(sequenceGenerator: SequenceGenerator, rewardCalculator: RewardCalculator) {
        self.sequence = sequenceGenerator
        self.reward = rewardCalculator
    }

    func step() -> (Int, Double) {
        let value = self.sequence.nextValue()
        let reward = self.reward.calculate()
        return (value, reward)
    }
}

func main() {
    let base = 1
    let increment = 1
    let initialReward = 100.0
    let decayRate = 0.99
    let sequenceGenerator = SequenceGenerator(base: base, increment: increment)
    let rewardCalculator = RewardCalculator(initialReward: initialReward, decayRate: decayRate)
    let environment = Environment(sequenceGenerator: sequenceGenerator, rewardCalculator: rewardCalculator)
    while true {
        let (value, reward) = environment.step()
        print("Value: \(value), Reward: \(reward)")
    }
}

main()