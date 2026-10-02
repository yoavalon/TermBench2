import Foundation

func initialize_environment() -> (Int, Double, Double) {
    let state = Int.random(in: 0..<100)
    let reward = 100.0
    let decay_rate = 0.99
    return (state, reward, decay_rate)
}

func update_state(state: Int, action: Int) -> Int {
    if action == 0 {
        return state + 1
    } else {
        return state - 1
    }
}

func calculate_reward(state: Int, reward: Double, decay_rate: Double, steps: Int) -> Double {
    return reward * pow(decay_rate, Double(steps))
}

func terminate_condition(state: Int) -> Bool {
    return state == 50
}

func agent_action(state: Int) -> Int {
    if state < 50 {
        return 0
    } else {
        return 1
    }
}

func main() {
    let (state, reward, decay_rate) = initialize_environment()
    var steps = 0
    var currentState = state
    var currentReward = reward
    while !terminate_condition(state: currentState) {
        let action = agent_action(state: currentState)
        currentState = update_state(state: currentState, action: action)
        steps += 1
        currentReward = calculate_reward(state: currentState, reward: currentReward, decay_rate: decay_rate, steps: steps)
    }
    print("Final State: \(currentState), Reward: \(String(format: "%.2f", currentReward)), Steps: \(steps)")
}

main()