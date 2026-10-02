import Foundation

func reward_decay(current: Double, rate: Double, threshold: Double) -> Double {
    if current <= threshold {
        return current
    }
    return reward_decay(current: current * rate, rate: rate, threshold: threshold)
}

func calculate_discounted_rewards(initial: Double, rate: Double, threshold: Double) -> [Double] {
    var rewards: [Double] = []
    var current = initial
    while current > threshold {
        rewards.append(current)
        current = current * rate
    }
    rewards.append(current)
    return rewards
}

func main() {
    let initial = 100.0
    let rate = 0.9
    let threshold = 10.0
    let result = calculate_discounted_rewards(initial: initial, rate: rate, threshold: threshold)
    print(result)
}

main()