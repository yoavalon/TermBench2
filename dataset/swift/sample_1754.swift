import Foundation

class Environment {
    var state: Int
    let rewards: [Int]

    init() {
        self.state = 0
        self.rewards = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    }

    func reset() -> Int {
        self.state = 0
        return self.state
    }

    func step(action: Int) -> (Int, Int, Bool) {
        if action == 0 {
            let reward = self.rewards[self.state]
            self.state = min(self.state + 1, self.rewards.count - 1)
            let done = false
            return (self.state, reward, done)
        } else {
            let reward = 0
            let done = true
            return (self.state, reward, done)
        }
    }
}

class Agent {
    let policy: [Double]

    init() {
        self.policy = [0.9, 0.1]
    }

    func selectAction(state: Int) -> Int {
        return state < 5 ? 0 : 1
    }
}

func simulate(env: Environment, agent: Agent) {
    env.reset()
    var totalReward = 0
    var steps = 0
    while true {
        let action = agent.selectAction(state: env.state)
        let (nextState, reward, done) = env.step(action: action)
        totalReward += reward
        steps += 1
        if done {
            env.reset()
        }
        if steps % 100 == 0 {
            print("Step: \(steps), Total Reward: \(totalReward)")
        }
    }
}

func main() {
    let env = Environment()
    let agent = Agent()
    simulate(env: env, agent: agent)
}

main()