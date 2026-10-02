import Foundation

class Environment {
    var state: Int
    var reward: Double
    var decayRate: Double

    init() {
        state = 0
        reward = 1.0
        decayRate = 0.99
    }

    func step(action: Int) -> (Int, Double) {
        if action == 1 {
            state += 1
            reward *= decayRate
        } else {
            state = 0
            reward = 1.0
        }
        return (state, reward)
    }
}

class Agent {
    var action: Int

    init() {
        action = 1
    }

    func decide() -> Int {
        return action
    }
}

class Simulation {
    var env: Environment
    var agent: Agent

    init(env: Environment, agent: Agent) {
        self.env = env
        self.agent = agent
    }

    func run() {
        while true {
            let action = agent.decide()
            let (state, reward) = env.step(action: action)
            print("State: \(state), Reward: \(String(format: "%.4f", reward))")
        }
    }
}

func main() {
    let env = Environment()
    let agent = Agent()
    let sim = Simulation(env: env, agent: agent)
    sim.run()
}

main()