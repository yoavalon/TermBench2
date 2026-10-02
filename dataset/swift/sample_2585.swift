func reward_decay(init_val: Double, decay_rate: Double, steps: Int) -> [Double] {
    var rewards: [Double] = []
    var current_val = init_val
    for _ in 0..<steps {
        rewards.append(current_val)
        current_val *= decay_rate
    }
    return rewards
}

func analyze_rewards(rewards: [Double]) -> (Double, Double) {
    let total = rewards.reduce(0, +)
    let avg = total / Double(rewards.count)
    return (total, avg)
}

func main() {
    let initial_value = 1.0
    let decay_rate = 0.9
    let number_of_steps = 10
    let sequence = reward_decay(init_val: initial_value, decay_rate: decay_rate, steps: number_of_steps)
    let (total, average) = analyze_rewards(rewards: sequence)
    print("Total: \(total), Average: \(average)")
}

main()