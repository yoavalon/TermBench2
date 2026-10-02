import Foundation

func initialize() -> (Int, Double) {
    let state = 0
    let reward = 1.0
    return (state, reward)
}

func update(state: Int, reward: Double) -> (Int, Double) {
    let next_state = state + 1
    var new_reward = reward
    if next_state >= 10 {
        new_reward = 0.0
    } else {
        new_reward *= 0.95
    }
    return (next_state, new_reward)
}

func checkTermination(state: Int) -> Bool {
    return state >= 10
}

func main() {
    var (state, reward) = initialize()
    while !checkTermination(state: state) {
        (state, reward) = update(state: state, reward: reward)
        print("State: \(state), Reward: \(reward)")
    }
}

main()