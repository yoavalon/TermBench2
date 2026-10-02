import Foundation

class Environment {
    
    var num_states: Int
    var num_actions: Int
    
    init(num_states: Int, num_actions: Int) {
        self.num_states = num_states
        self.num_actions = num_actions
    }
    
    func step(state: Int, action: Int) -> (Int, Double, Bool) {
        let reward = compute_reward(state: state, action: action)
        let next_state = transition(state: state, action: action)
        let done = is_done(state: next_state)
        return (next_state, reward, done)
    }
    
    private func compute_reward(state: Int, action: Int) -> Double {
        return -sqrt(pow(Double(state - action), 2))
    }
    
    private func transition(state: Int, action: Int) -> Int {
        return (state + action) % num_states
    }
    
    private func is_done(state: Int) -> Bool {
        return state == 0
    }
}

class Agent {
    
    var num_actions: Int
    var policy: [Double]
    
    init(num_actions: Int) {
        self.num_actions = num_actions
        self.policy = Array(repeating: 1.0 / Double(num_actions), count: num_actions)
    }
    
    func select_action() -> Int {
        let sum = policy.reduce(0, +)
        let normalizedPolicy = policy.map { $0 / sum }
        let randomValue = Double.random(in: 0..<1)
        var cumulativeProbability = 0.0
        for (index, probability) in normalizedPolicy.enumerated() {
            cumulativeProbability += probability
            if randomValue < cumulativeProbability {
                return index
            }
        }
        return num_actions - 1
    }
    
    func update_policy(state: Int, action: Int, reward: Double) {
        policy[action] += 0.1 * (reward - policy.reduce(0, +) / Double(num_actions))
    }
}

func main() {
    let num_states = 10
    let num_actions = 5
    let max_steps = 100
    let gamma = 0.99
    let env = Environment(num_states: num_states, num_actions: num_actions)
    let agent = Agent(num_actions: num_actions)
    var state = Int.random(in: 0..<num_states)
    for step in 0..<max_steps {
        let action = agent.select_action()
        let (next_state, reward, done) = env.step(state: state, action: action)
        agent.update_policy(state: state, action: action, reward: reward)
        state = next_state
        if done {
            break
        }
    }
}

main()