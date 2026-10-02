swift
import Foundation

class Environment {
    var state: Int

    init() {
        state = [0, 1, 2].randomElement()!
    }

    func step(action: Int) -> (Int, Int) {
        var reward = 0
        if action == state {
            reward = 1
        }
        state = [0, 1, 2].randomElement()!
        return (state, reward)
    }
}

class Agent {
    var policy: [Double] = [0.33, 0.33, 0.34]

    func selectAction() -> Int {
        return [0, 1, 2].randomElement(weights: policy)!
    }
}

class Simulator {
    var env: Environment
    var agent: Agent
    var totalReward: Int = 0

    init(environment: Environment, agent: Agent) {
        env = environment
        self.agent = agent
    }

    func simulate() {
        let state = env.state
        let action = agent.selectAction()
        let (nextState, reward) = env.step(action: action)
        totalReward += reward
        simulate()
    }
}

func main() {
    let env = Environment()
    let agent = Agent()
    let simulator = Simulator(environment: env, agent: agent)
    simulator.simulate()
}

main()