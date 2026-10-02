import Foundation

class Environment {
    var state: Int
    let actionSpace: [Int]

    init() {
        state = Int.random(in: 0..<10)
        actionSpace = [0, 1]
    }

    func step(action: Int) -> (Int, Double, Bool) {
        var reward = 0.0
        if action == 0 {
            reward = 1.0 - Double(state) / 10.0
        } else {
            reward = Double(state) / 10.0
        }
        state = Int.random(in: 0..<10)
        return (state, reward, isDone())
    }

    func isDone() -> Bool {
        return Double.random(in: 0.0..<1.0) < 0.05
    }
}

class Agent {
    let actionSpace: [Int]
    var epsilon: Double

    init(actionSpace: [Int]) {
        self.actionSpace = actionSpace
        epsilon = 1.0
    }

    func chooseAction(state: Int) -> Int {
        if Double.random(in: 0.0..<1.0) < epsilon {
            return actionSpace.randomElement()!
        } else {
            return policy(state: state)
        }
    }

    func policy(state: Int) -> Int {
        return state < 5 ? 0 : 1
    }
}

func train(agent: Agent, env: Environment, episodes: Int) {
    for _ in 0..<episodes {
        var state = env.state
        var done = false
        while !done {
            let action = agent.chooseAction(state: state)
            let (nextState, reward, done) = env.step(action: action)
            state = nextState
        }
        agent.epsilon = max(0.01, agent.epsilon * 0.99)
    }
}

func main() {
    let env = Environment()
    let agent = Agent(actionSpace: env.actionSpace)
    let episodes = 1000
    train(agent: agent, env: env, episodes: episodes)
}

main()