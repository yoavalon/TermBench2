import Foundation

class Environment {
    var state: [Double]

    init(size: Int) {
        self.state = Array(repeating: 0.0, count: size)
    }

    func reset() -> [Double] {
        self.state = Array(repeating: 0.0, count: self.state.count)
        return self.state
    }

    func step(action: Int) -> ([Double], Double, Bool) {
        let reward = Double.random(in: -1...1)
        self.state[action] += 1
        var done = false
        if self.state.contains(where: { $0 > 10 }) {
            done = true
        }
        return (self.state, reward, done)
    }
}

class Agent {
    var actionSpace: [Int]

    init(actionSpace: [Int]) {
        self.actionSpace = actionSpace
    }

    func chooseAction() -> Int {
        return actionSpace.randomElement() ?? 0
    }
}

func trainAgent(env: Environment, agent: Agent, episodes: Int, decayRate: Double) -> [Double] {
    var rewards: [Double] = []
    for episode in 0..<episodes {
        let state = env.reset()
        var totalReward = 0.0
        for _ in 0..<100 {
            let action = agent.chooseAction()
            let (state, reward, done) = env.step(action: action)
            totalReward += reward
            if done {
                break
            }
        }
        rewards.append(totalReward)
        if episode > 0 && episode % 10 == 0 {
            rewards = rewards.map { $0 * decayRate }
        }
    }
    return rewards
}

func main() {
    let envSize = 5
    let actionSpace = Array(0..<envSize)
    let env = Environment(size: envSize)
    let agent = Agent(actionSpace: actionSpace)
    let episodes = 50
    let decayRate = 0.9
    trainAgent(env: env, agent: agent, episodes: episodes, decayRate: decayRate)
}

main()