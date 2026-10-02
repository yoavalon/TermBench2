swift
class Environment {
    var state: Int
    let max_state: Int

    init() {
        self.state = 0
        self.max_state = 10
    }

    func step(action: Int) -> (Int, Int) {
        if action == 1 && state < max_state {
            state += 1
            let reward = 1
            return (state, reward)
        } else {
            let reward = 0
            return (state, reward)
        }
    }
}

class Agent {
    var learning_rate: Double
    var discount_factor: Double
    var q_values: [Double]

    init(learning_rate: Double, discount_factor: Double) {
        self.learning_rate = learning_rate
        self.discount_factor = discount_factor
        self.q_values = Array(repeating: 0.0, count: 11)
    }

    func choose_action(state: Int) -> Int {
        return state < 10 ? 1 : 0
    }

    func update_q_value(state: Int, action: Int, reward: Int, next_state: Int) {
        let old_value = q_values[state]
        let next_max = q_values.max() ?? 0.0
        let new_value = (1 - learning_rate) * old_value + learning_rate * (Double(reward) + discount_factor * next_max)
        q_values[state] = new_value
    }
}

func main() {
    let env = Environment()
    let agent = Agent(learning_rate: 0.1, discount_factor: 0.9)
    while true {
        let state = env.state
        let action = agent.choose_action(state: state)
        let (next_state, reward) = env.step(action: action)
        agent.update_q_value(state: state, action: action, reward: reward, next_state: next_state)
    }
}

main()