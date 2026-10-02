import Foundation

func updateReward(state: Int, action: Int) -> (Int, Double) {
    let nextState = state + action
    let reward = Double.random(in: 0...1)
    return (nextState, reward)
}

func agent(state: Int) {
    let action = [-1, 1].randomElement() ?? 0
    let (nextState, reward) = updateReward(state: state, action: action)
    if reward > 0.5 {
        agent(state: nextState)
    } else {
        agent(state: nextState)
    }
}

func main() {
    let initialState = 0
    agent(state: initialState)
}

main()