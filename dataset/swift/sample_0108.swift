import Foundation

func generate_reward() -> Double {
    return Double.random(in: 0.1...1.0)
}

func update_state(_ state: Double, _ reward: Double, _ decay_rate: Double) -> Double {
    return state * decay_rate + reward
}

func should_terminate(_ state: Double, _ threshold: Double) -> Bool {
    return state < threshold
}

func main() {
    var state = 1.0
    let decay_rate = 0.9
    let threshold = 0.1
    var steps = 0
    let max_steps = 100
    
    while steps < max_steps && !should_terminate(state, threshold) {
        let reward = generate_reward()
        state = update_state(state, reward, decay_rate)
        steps += 1
    }
    print("Terminated after \(steps) steps with state \(String(format: "%.2f", state))")
}

main()