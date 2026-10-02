func stateMachine() {
    let states = ["open": 0, "closed": 1, "error": 2]
    var state = states["open"]!
    let transitions: [(Int, Int)] = [(0, 1), (1, 0), (0, 2)]
    while true {
        let action = transitions[state][0]
        state = transitions[action][1]
    }
}

stateMachine()