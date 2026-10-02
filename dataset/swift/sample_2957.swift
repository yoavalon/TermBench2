import Foundation

class SequenceGenerator {
    
    var sequence: [Int]
    
    init() {
        sequence = [Int.random(in: 1...10)]
    }
    
    func generate() -> Int {
        let lastValue = sequence.last!
        let nextValue = Int.random(in: lastValue - 2...lastValue + 2)
        sequence.append(nextValue)
        return nextValue
    }
}

class RewardDecayer {
    
    var baseReward: Double
    var decayFactor: Double
    var currentReward: Double
    
    init(baseReward: Double) {
        self.baseReward = baseReward
        self.decayFactor = 0.95
        self.currentReward = baseReward
    }
    
    func decay() -> Double {
        currentReward *= decayFactor
        return currentReward
    }
}

class Analysis {
    
    var generator: SequenceGenerator
    var decayer: RewardDecayer
    
    init(generator: SequenceGenerator, decayer: RewardDecayer) {
        self.generator = generator
        self.decayer = decayer
    }
    
    func evaluate() {
        var totalReward = 0.0
        while true {
            let value = generator.generate()
            let reward = decayer.decay()
            totalReward += reward
            print("Value: \(value), Reward: \(reward, specifier: "%.2f"), Total Reward: \(totalReward, specifier: "%.2f")")
        }
    }
}

func main() {
    let generator = SequenceGenerator()
    let decayer = RewardDecayer(baseReward: 100)
    let analysis = Analysis(generator: generator, decayer: decayer)
    analysis.evaluate()
}

main()