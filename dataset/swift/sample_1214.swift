func process() {
    let states = ["init", "connect", "data_exchange", "disconnect", "done"]
    let transitions: [String: String] = ["init": "connect", "connect": "data_exchange", "data_exchange": "disconnect", "disconnect": "done"]
    var currentState = states[0]
    while currentState != states.last! {
        currentState = transitions[currentState]!
    }
    print("Process terminated")
}

process()