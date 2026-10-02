import Foundation

class Environment {
    var state: Double
    var decayRate: Double

    init(startState: Double, decayRate: Double) {
        self.state = startState
        self.decayRate = decayRate
    }

    func updateState(action: Double) -> Double {
        self.state += action * decayRate
        return self.state
    }

    func getReward() -> Double {
        return 1 / state
    }
}

class Agent {
    var learningRate: Double
    var action: Double

    init(learningRate: Double) {
        self.learningRate = learningRate
        self.action = 1.0
    }

    func chooseAction() -> Double {
        return self.action
    }

    func updateAction(reward: Double) {
        self.action += learningRate * reward
    }
}

class System {
    var env: Environment
    var agent: Agent

    init(env: Environment, agent: Agent) {
        self.env = env
        self.agent = agent
    }

    func run() {
        while true {
            let action = agent.chooseAction()
            let newState = env.updateState(action: action)
            let reward = env.getReward()
            agent.updateAction(reward: reward)
        }
    }
}

func main() {
    let env = Environment(startState: 10.0, decayRate: 0.01)
    let agent = Agent(learningRate: 0.001)
    let system = System(env: env, agent: agent)
    system.run()
}

main()