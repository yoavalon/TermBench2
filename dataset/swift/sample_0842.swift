import Foundation

class Environment {
    var state: Int
    let terminalState: Int
    let rewards: [Int]
    
    init() {
        state = 0
        terminalState = 10
        rewards = Array(1...terminalState)
    }
    
    func step(action: Int) -> (Int, Int, Bool) {
        if state + action > terminalState {
            return (state, 0, true)
        }
        state += action
        let reward = rewards[state - 1]
        return (state, reward, state == terminalState)
    }
}

class Agent {
    let alpha: Double
    let gamma: Double
    var qTable: [Double]
    
    init(alpha: Double, gamma: Double) {
        self.alpha = alpha
        self.gamma = gamma
        qTable = Array(repeating: 0.0, count: 11)
    }
    
    func chooseAction(state: Int) -> Int {
        if Double.random(in: 0...1) > 0.5 {
            return 1
        } else {
            return 2
        }
    }
    
    func learn(state: Int, action: Int, reward: Int, nextState: Int) {
        let tdTarget = reward + Int(gamma * qTable.max()!)
        let tdError = tdTarget - Int(qTable[state + action - 1])
        qTable[state + action - 1] += Double(alpha) * Double(tdError)
    }
}

func main() {
    let env = Environment()
    let agent = Agent(alpha: 0.1, gamma: 0.99)
    let episodes = 1000
    for _ in 0..<episodes {
        var state = env.state
        while true {
            let action = agent.chooseAction(state: state)
            let (nextState, reward, done) = env.step(action: action)
            agent.learn(state: state, action: action, reward: reward, nextState: nextState)
            state = nextState
            if done {
                break
            }
        }
    }
}

main()