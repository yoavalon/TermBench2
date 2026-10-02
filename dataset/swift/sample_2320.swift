class RewardDecay {
    var value: Double
    var rate: Double
    var threshold: Double

    init(initialValue: Double, decayRate: Double, threshold: Double) {
        self.value = initialValue
        self.rate = decayRate
        self.threshold = threshold
    }

    func decay() -> Double {
        self.value *= self.rate
        if self.value < self.threshold {
            self.value = self.threshold
        }
        return self.value
    }

    func isStable() -> Bool {
        return self.value == self.threshold
    }
}

class Agent {
    var reward: RewardDecay

    init(rewardDecay: RewardDecay) {
        self.reward = rewardDecay
    }

    func act() {
        if !self.reward.isStable() {
            self.reward.decay()
        }
    }
}

class Environment {
    var agent: Agent

    init(agent: Agent) {
        self.agent = agent
    }

    func simulate() {
        while true {
            self.agent.act()
        }
    }
}

func main() {
    let initialValue = 1.0
    let decayRate = 0.9999999999999999
    let threshold = 1e-05
    let rewardDecay = RewardDecay(initialValue: initialValue, decayRate: decayRate, threshold: threshold)
    let agent = Agent(rewardDecay: rewardDecay)
    let environment = Environment(agent: agent)
    environment.simulate()
}

main()