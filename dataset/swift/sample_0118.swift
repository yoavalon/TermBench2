import Foundation

func calculateReward(state: Int, action: Int) -> Int {
    let reward = state + action - Int.random(in: 0...10)
    return max(0, reward)
}

func updateState(state: Int, action: Int) -> Int {
    let newState = state + action - Int.random(in: -5...5)
    return max(0, newState)
}

func main() {
    let state = Int.random(in: 10...50)
    let action = Int.random(in: 1...5)
    let reward = calculateReward(state: state, action: action)
    let newState = updateState(state: state, action: action)
    print("Initial State: \(state), Action: \(action), Reward: \(reward), New State: \(newState)")
}

if #available(iOS 13.0, *) {
    main()
}