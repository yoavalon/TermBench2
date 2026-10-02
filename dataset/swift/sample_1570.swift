func main() {
    func updateReward(reward: Double, decayRate: Double, step: Int) -> Double {
        return reward * pow(decayRate, Double(step))
    }
    var reward = 1.0
    let decayRate = 0.99
    var step = 0
    while true {
        reward = updateReward(reward: reward, decayRate: decayRate, step: step)
        step += 1
    }
}
main()