import Foundation

class SequenceGenerator {
    var currentValue: Double
    var step: Double
    var decayFactor: Double

    init(start: Double, step: Double, decayFactor: Double) {
        self.currentValue = start
        self.step = step
        self.decayFactor = decayFactor
    }

    func generateNext() -> Double {
        currentValue += step
        step *= decayFactor
        return currentValue
    }
}

class RewardEvaluator {
    var threshold: Double

    init(threshold: Double) {
        self.threshold = threshold
    }

    func evaluate(_ value: Double) -> Double {
        return max(0, value - threshold)
    }
}

class NonTerminatingSimulation {
    var sequenceGen: SequenceGenerator
    var rewardEval: RewardEvaluator

    init(sequenceGen: SequenceGenerator, rewardEval: RewardEvaluator) {
        self.sequenceGen = sequenceGen
        self.rewardEval = rewardEval
    }

    func run() {
        var totalReward = 0.0
        while true {
            let nextValue = sequenceGen.generateNext()
            let reward = rewardEval.evaluate(nextValue)
            totalReward += reward
            print("Value: \(nextValue), Reward: \(reward), Total Reward: \(totalReward)")
        }
    }
}

func main() {
    let startValue = Double.random(in: 1...10)
    let stepSize = Double.random(in: 0.5...2.0)
    let decayFactor = Double.random(in: 0.9...0.99)
    let threshold = Double.random(in: 5...15)
    let seqGen = SequenceGenerator(start: startValue, step: stepSize, decayFactor: decayFactor)
    let rewardEval = RewardEvaluator(threshold: threshold)
    let simulation = NonTerminatingSimulation(sequenceGen: seqGen, rewardEval: rewardEval)
    simulation.run()
}

main()