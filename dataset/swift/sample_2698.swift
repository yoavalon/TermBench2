import Foundation

class SequenceGenerator {
    var value: Double
    var decay: Double
    
    init(initialValue: Double, decayFactor: Double) {
        self.value = initialValue
        self.decay = decayFactor
    }
    
    func generate(steps: Int) -> [Double] {
        var sequence: [Double] = []
        for _ in 0..<steps {
            sequence.append(self.value)
            self.value *= self.decay
        }
        return sequence
    }
}

class RewardCalculator {
    var sequence: [Double]
    
    init(sequence: [Double]) {
        self.sequence = sequence
    }
    
    func calculateRewards() -> [Double] {
        var rewards: [Double] = []
        for value in self.sequence {
            let reward = value > 0 ? value : 0
            rewards.append(reward)
        }
        return rewards
    }
}

class Analysis {
    var rewards: [Double]
    
    init(rewards: [Double]) {
        self.rewards = rewards
    }
    
    func averageReward() -> Double {
        return rewards.reduce(0, +) / Double(rewards.count)
    }
    
    func totalReward() -> Double {
        return rewards.reduce(0, +)
    }
}

func main() {
    let initialValue = 100.0
    let decayFactor = 0.95
    let steps = 100
    let sequenceGenerator = SequenceGenerator(initialValue: initialValue, decayFactor: decayFactor)
    let sequence = sequenceGenerator.generate(steps: steps)
    let rewardCalculator = RewardCalculator(sequence: sequence)
    let rewards = rewardCalculator.calculateRewards()
    let analysis = Analysis(rewards: rewards)
    let avgReward = analysis.averageReward()
    let totalReward = analysis.totalReward()
    print("Average Reward:", avgReward)
    print("Total Reward:", totalReward)
}

main()