class SequenceGenerator {
    var start: Int
    var end: Int
    var step: Int
    var current: Int

    init(start: Int, end: Int, step: Int) {
        self.start = start
        self.end = end
        self.step = step
        self.current = start
    }

    func generate() -> AnySequence<Int> {
        return AnySequence {
            return AnyIterator {
                if self.current < self.end {
                    let value = self.current
                    self.current += self.step
                    return value
                } else {
                    return nil
                }
            }
        }
    }
}

class RewardCalculator {
    var initialReward: Double
    var decayRate: Double
    var currentReward: Double

    init(initialReward: Double, decayRate: Double) {
        self.initialReward = initialReward
        self.decayRate = decayRate
        self.currentReward = initialReward
    }

    func calculate(step: Int) -> Double {
        self.currentReward = self.initialReward * pow(self.decayRate, Double(step))
        return self.currentReward
    }
}

func simulate(sequenceGenerator: SequenceGenerator, rewardCalculator: RewardCalculator, maxSteps: Int) -> Double {
    var steps = 0
    var totalReward = 0.0
    for value in sequenceGenerator.generate() {
        if steps >= maxSteps {
            break
        }
        let reward = rewardCalculator.calculate(step: steps)
        totalReward += reward
        steps += 1
    }
    return totalReward
}

func main() {
    let seqGen = SequenceGenerator(start: 0, end: 10, step: 1)
    let rewardCalc = RewardCalculator(initialReward: 1.0, decayRate: 0.9)
    let maxSteps = 5
    let result = simulate(sequenceGenerator: seqGen, rewardCalculator: rewardCalc, maxSteps: maxSteps)
    print(result)
}

main()