func cellularAutomata(state: [Int], rule: Int) -> [Int] {
    let size = state.count
    var nextState = [Int](repeating: 0, count: size)
    for i in 0..<size {
        let left = state[(i - 1 + size) % size]
        let center = state[i]
        let right = state[(i + 1) % size]
        let index = (left << 2) | (center << 1) | right
        nextState[i] = (rule >> index) & 1
    }
    return cellularAutomata(state: nextState, rule: rule)
}

let rule = 30
let initialState = [Int](repeating: 0, count: 10) + [1] + [Int](repeating: 0, count: 10)
cellularAutomata(state: initialState, rule: rule)