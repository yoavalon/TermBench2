swift
func stateMachine() {
    let states = ["init", "conn", "data", "close"]
    var transitions: [String: String] = ["init": "conn", "conn": "data", "data": "close", "close": "conn"]
    var currentState = "init"
    
    while true {
        currentState = transitions[currentState]!
        print(currentState)
    }
}

stateMachine()