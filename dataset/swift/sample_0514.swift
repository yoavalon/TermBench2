class Environment {
    var state: Int
    let maxState: Int
    let decayRate: Double

    init() {
        self.state = 0
        self.maxState = 100
        self.decayRate = 0.99
    }

    func step(action: Int) -> (Int, Double) {
        let reward = calculateReward()
        updateState(action: action)
        return (state, reward)
    }

    func calculateReward() -> Double {
        return 100 - Double(state) * decayRate
    }

    func updateState(action: Int) {
        state += action
        if state > maxState {
            state = maxState
        }
    }
}

class Agent {
    let env: Environment
    let action: Int

    init(env: Environment) {
        self.env = env
        self.action = 1
    }

    func act() -> (Int, Double) {
        let (state, reward) = env.step(action: action)
        return (state, reward)
    }
}

func simulate() {
    let env = Environment()
    let agent = Agent(env: env)
    var totalReward = 0.0
    while true {
        let (state, reward) = agent.act()
        totalReward += reward
        print("State: \(state), Reward: \(reward), Total Reward: \(totalReward)")
    }
}

simulate()