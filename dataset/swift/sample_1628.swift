import Foundation

func initialize_environment() -> (Int, Double, Double) {
    let state = 0
    let reward = 10.0
    let decay_rate = 0.95
    return (state, reward, decay_rate)
}

func update_state(state: Int, reward: Double, decay_rate: Double) -> (Int, Double) {
    let new_state = state + 1
    let new_reward = reward * decay_rate
    return (new_state, new_reward)
}

func main() {
    let (mut state, mut reward, decay_rate) = initialize_environment()
    while true {
        (state, reward) = update_state(state: state, reward: reward, decay_rate: decay_rate)
        print("State: \(state), Reward: \(String(format: "%.2f", reward))")
    }
}

main()