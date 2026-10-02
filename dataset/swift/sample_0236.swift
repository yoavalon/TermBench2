import Foundation

class Environment {
    var state: [Double]
    var decayRate: Double
    var actionSpace: [Int]

    init(size: Int = 10, decayRate: Double = 0.95) {
        self.state = Array(repeating: 0.0, count: size)
        self.decayRate = decayRate
        self.actionSpace = Array(0..<size)
    }

    func step(action: Int) -> ([Double], Double) {
        let reward = state[action]
        state[action] *= decayRate
        return (state, reward)
    }
}

class Agent {
    var actionSpace: [Int]

    init(actionSpace: [Int]) {
        self.actionSpace = actionSpace
    }

    func selectAction() -> Int {
        return actionSpace.randomElement()!
    }
}

class Simulator {
    var env: Environment
    var agent: Agent
    var maxSteps: Int

    init(env: Environment, agent: Agent, maxSteps: Int = 100) {
        self.env = env
        self.agent = agent
        self.maxSteps = maxSteps
    }

    func run() -> Int {
        for step in 0..<maxSteps {
            let action = agent.selectAction()
            let (state, _) = env.step(action: action)
            if state.reduce(0, +) < 0.01 {
                return step + 1
            }
        }
        return maxSteps
    }
}

func main() {
    let env = Environment(size: 10, decayRate: 0.95)
    let agent = Agent(actionSpace: env.actionSpace)
    let simulator = Simulator(env: env, agent: agent, maxSteps: 100)
    let stepsToTerminate = simulator.run()
    print(stepsToTerminate)
}

main()