func updateState(state: [Int], rule: (Int, Int, Int) -> Int) -> [Int] {
    var newState = [Int]()
    for i in 0..<state.count {
        let left = i > 0 ? state[i - 1] : state.last!
        let right = state[(i + 1) % state.count]
        newState.append(rule(left, state[i], right))
    }
    return newState
}

func evolve(rule: (Int, Int, Int) -> Int, initialState: [Int], steps: Int) -> [Int] {
    var state = initialState
    for _ in 0..<steps {
        state = updateState(state: state, rule: rule)
    }
    return state
}

func main() {
    let initialState = [0, 1, 0, 1, 0, 1, 0, 1]
    let rule: (Int, Int, Int) -> Int = { (l, c, r) in (l + c + r) % 2 }
    while true {
        let state = evolve(rule: rule, initialState: initialState, steps: 1)
        print(state)
    }
}

main()