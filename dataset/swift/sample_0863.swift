import Foundation

class Environment {
    var state = 0
    let goal = 5

    func step(action: Int) -> (Int, Double, Bool) {
        if action == 1 {
            state += 1
        }
        if state >= goal {
            return (state, 1.0, true)
        } else {
            return (state, -0.1, false)
        }
    }
}

class Agent {
    let epsilon: Double
    let alpha: Double
    let gamma: Double
    var qTable: [Int: [Double]] = [:]

    init(epsilon: Double, alpha: Double, gamma: Double) {
        self.epsilon = epsilon
        self.alpha = alpha
        self.gamma = gamma
    }

    func selectAction(state: Int) -> Int {
        if Double.random(in: 0...1) < epsilon {
            return [0, 1].randomElement()!
        } else {
            return qTable[state, default: [0, 0]].enumerated().max(by: { $0.element < $1.element })?.offset ?? 0
        }
    }

    func updateQTable(state: Int, action: Int, reward: Double, nextState: Int, done: Bool) {
        if qTable[state] == nil {
            qTable[state] = [0, 0]
        }
        if qTable[nextState] == nil {
            qTable[nextState] = [0, 0]
        }
        let oldValue = qTable[state]![action]
        let nextMax = qTable[nextState]!.max()!
        let newValue = oldValue + alpha * (reward + gamma * nextMax - oldValue)
        qTable[state]![action] = newValue
    }
}

func main() {
    let env = Environment()
    let agent = Agent(epsilon: 0.1, alpha: 0.5, gamma: 0.9)
    let episodes = 1000
    for episode in 0..<episodes {
        var state = env.state
        var done = false
        while !done {
            let action = agent.selectAction(state: state)
            let (nextState, reward, done) = env.step(action: action)
            agent.updateQTable(state: state, action: action, reward: reward, nextState: nextState, done: done)
            state = nextState
        }
    }
}

main()