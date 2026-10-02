func boundary_conditions(state: Int, reward: Double, decay_rate: Double) -> Double {
    var reward = reward
    reward *= decay_rate
    if reward < 0.1 {
        return 0
    }
    return reward
}

func main() {
    let state = 1
    var reward = 1.0
    let decay_rate = 0.9
    for _ in 0..<10 {
        reward = boundary_conditions(state: state, reward: reward, decay_rate: decay_rate)
        print(reward)
    }
}

main()