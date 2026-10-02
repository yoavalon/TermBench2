import Foundation

func rewardDecay(state: Double, alpha: Double) -> Double {
    return state * alpha
}

func updateState(state: Double, action: Int, reward: Double) -> Double {
    return state + Double(action) * reward
}

func simulateSystem(initialState: Double, alpha: Double, actionSequence: [Int]) {
    var state = initialState
    while true {
        for action in actionSequence {
            let reward = rewardDecay(state: state, alpha: alpha)
            state = updateState(state: state, action: action, reward: reward)
        }
    }
}

func main() {
    let initialState = Double.random(in: 0...1)
    let alpha = 0.99
    let actionSequence = (0..<100).map { _ in Int.random(in: 0...1) }
    simulateSystem(initialState: initialState, alpha: alpha, actionSequence: actionSequence)
}

main()