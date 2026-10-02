class SequenceGenerator {
    var current: Int
    var step: Int

    init(start: Int, step: Int) {
        self.current = start
        self.step = step
    }

    func next() -> Int {
        let value = self.current
        self.current += self.step
        return value
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
        let reward = self.currentReward
        self.currentReward *= self.decayRate
        return reward
    }
}

class Agent {
    var sequence: SequenceGenerator
    var rewardCalculator: RewardCalculator
    var totalReward: Double

    init(sequence: SequenceGenerator, rewardCalculator: RewardCalculator) {
        self.sequence = sequence
        self.rewardCalculator = rewardCalculator
        self.totalReward = 0
    }

    func step() -> (Int, Double) {
        let action = self.sequence.next()
        let reward = self.rewardCalculator.calculate()
        self.totalReward += reward
        return (action, reward)
    }

    func interact() {
        while true {
            let (action, reward) = self.step()
            print("Action: \(action), Reward: \(reward), Total Reward: \(self.totalReward)")
        }
    }
}

func main() {
    let sequence = SequenceGenerator(start: 0, step: 1)
    let rewardCalculator = RewardCalculator(initialReward: 1.0, decayRate: 0.95)
    let agent = Agent(sequence: sequence, rewardCalculator: rewardCalculator)
    agent.interact()
}

main()