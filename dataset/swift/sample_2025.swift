import Foundation

class RewardSystem {
    var value: Double
    var decayRate: Double

    init(initialValue: Double, decayRate: Double) {
        self.value = initialValue
        self.decayRate = decayRate
    }

    func decay() -> Double {
        self.value *= self.decayRate
        return self.value
    }
}

class Environment {
    var rewardSystem: RewardSystem

    init(rewardSystem: RewardSystem) {
        self.rewardSystem = rewardSystem
    }

    func step() -> Double {
        let reward = self.rewardSystem.decay()
        return reward
    }
}

class Agent {
    var environment: Environment

    init(environment: Environment) {
        self.environment = environment
    }

    func act() -> Double {
        return self.environment.step()
    }
}

func main() {
    let initialValue = 1.0
    let decayRate = 0.99
    let rewardSystem = RewardSystem(initialValue: initialValue, decayRate: decayRate)
    let environment = Environment(rewardSystem: rewardSystem)
    let agent = Agent(environment: environment)
    let threshold = 0.01
    var iterations = 0
    while true {
        let reward = agent.act()
        iterations += 1
        if reward < threshold {
            break
        }
    }
    print("Terminated after \(iterations) iterations with reward \(String(format: "%.6f", reward))")
}

main()