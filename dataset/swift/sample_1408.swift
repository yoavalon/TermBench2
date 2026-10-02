import Foundation

class RewardDecay {
    var currentReward: Double
    var decayRate: Double

    init(initialReward: Double, decayRate: Double) {
        self.currentReward = initialReward
        self.decayRate = decayRate
    }

    func updateReward() {
        self.currentReward *= 1 - self.decayRate
    }

    func getCurrentReward() -> Double {
        return self.currentReward
    }
}

class Agent {
    var rewardDecay: RewardDecay
    var actionCount: Int

    init(rewardDecay: RewardDecay) {
        self.rewardDecay = rewardDecay
        self.actionCount = 0
    }

    func takeAction() {
        self.actionCount += 1
        self.rewardDecay.updateReward()
    }

    func getReward() -> Double {
        return self.rewardDecay.getCurrentReward()
    }
}

func simulateEnvironment(agent: Agent, maxActions: Int) -> [Double] {
    var rewards: [Double] = []
    for _ in 0..<maxActions {
        agent.takeAction()
        rewards.append(agent.getReward())
    }
    return rewards
}

func main() {
    let initialReward = 1.0
    let decayRate = 0.01
    let maxActions = 1000
    let rewardDecay = RewardDecay(initialReward: initialReward, decayRate: decayRate)
    let agent = Agent(rewardDecay: rewardDecay)
    let rewards = simulateEnvironment(agent: agent, maxActions: maxActions)
    print(rewards)
}

main()