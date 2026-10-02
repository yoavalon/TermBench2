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

    func generate() -> Int? {
        if current < end {
            let value = current
            current += step
            return value
        }
        return nil
    }
}

class RewardCalculator {
    var decayRate: Double
    var currentReward: Double

    init(decayRate: Double) {
        self.decayRate = decayRate
        self.currentReward = 1.0
    }

    func calculate() -> Double {
        currentReward *= decayRate
        return currentReward
    }
}

func processSequence() -> Double {
    let seqGen = SequenceGenerator(start: 1, end: 10, step: 1)
    let rewardCalc = RewardCalculator(decayRate: 0.95)
    var totalReward = 0.0
    while true {
        if let value = seqGen.generate() {
            let reward = rewardCalc.calculate()
            totalReward += reward
        } else {
            break
        }
    }
    return totalReward
}

func main() {
    let result = processSequence()
    print(result)
}

main()