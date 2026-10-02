import Foundation

func initializeEnvironment() -> Int {
    return Int.random(in: 0..<10)
}

func updateState(_ state: Int, _ action: Int) -> Int {
    return (state + action) % 10
}

func calculateReward(_ state: Int) -> Double {
    return sin(Double(state))
}

func decayReward(_ reward: Double, _ step: Int) -> Double {
    return reward * pow(0.9, Double(step))
}

func main() {
    var state = initializeEnvironment()
    var step = 0
    while true {
        let action = Int.random(in: 0..<3)
        state = updateState(state, action)
        let reward = calculateReward(state)
        let decayedReward = decayReward(reward, step)
        step += 1
    }
}

main()