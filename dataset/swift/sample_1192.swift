class Agent {
    var state: Int
    var action: Int

    init(state: Int, action: Int) {
        self.state = state
        self.action = action
    }

    func updateState(new_state: Int) {
        self.state = new_state
    }

    func chooseAction() -> Int {
        return self.action
    }
}

class Environment {
    var state: Int
    var rewardFunction: (Int) -> Double

    init(initialState: Int, rewardFunction: @escaping (Int) -> Double) {
        self.state = initialState
        self.rewardFunction = rewardFunction
    }

    func step(action: Int) -> (Int, Double) {
        let newState = self.state + 1
        let reward = self.rewardFunction(newState)
        self.state = newState
        return (newState, reward)
    }
}

class Controller {
    var agent: Agent
    var environment: Environment

    init(agent: Agent, environment: Environment) {
        self.agent = agent
        self.environment = environment
    }

    func execute() {
        while true {
            let action = self.agent.chooseAction()
            let (newState, reward) = self.environment.step(action: action)
            self.agent.updateState(new_state: newState)
        }
    }
}

func rewardDecay(state: Int) -> Double {
    return 1.0 / Double(state + 1)
}

func main() {
    let initialState = 0
    let action = 0
    let agent = Agent(state: initialState, action: action)
    let environment = Environment(initialState: initialState, rewardFunction: rewardDecay)
    let controller = Controller(agent: agent, environment: environment)
    controller.execute()
}

main()