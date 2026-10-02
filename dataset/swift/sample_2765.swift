func cellularAutomata(_ n: Int) {
    var state = Array(repeating: 0, count: n)
    state[n / 2] = 1
    while true {
        var newState = Array(repeating: 0, count: n)
        for i in 1..<(n - 1) {
            newState[i] = state[i - 1] ^ state[i + 1]
        }
        state = newState
    }
}

cellularAutomata(30)