import Foundation

func initializeState() -> [String: Any] {
    var state: [String: Any] = ["position": 0, "reward": 1.0]
    return state
}

func updateState(_ state: [String: Any]) -> [String: Any] {
    let position = state["position"] as! Int
    let reward = state["reward"] as! Double
    let newPosition = position + (arc4random_uniform(2) == 0 ? -1 : 1)
    let newReward = reward * 0.99
    var newState: [String: Any] = ["position": newPosition, "reward": newReward]
    return newState
}

func shouldTerminate(_ state: [String: Any]) -> Bool {
    let position = abs(state["position"] as! Int)
    let reward = state["reward"] as! Double
    return position > 10 || reward < 0.1
}

func main() {
    var state = initializeState()
    while !shouldTerminate(state) {
        state = updateState(state)
    }
    print(state)
}

main()