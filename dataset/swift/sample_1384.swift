func stateMachine(initialState: String, transitions: [(String, String): String], inputSequence: [String]) -> String {
    var currentState = initialState
    for signal in inputSequence {
        if let nextState = transitions[(currentState, signal)] {
            currentState = nextState
        } else {
            fatalError("Invalid state transition")
        }
    }
    return currentState
}

func processNetworkData(data: [String]) {
    let initial = "idle"
    let transitions: [(String, String): String] = [("idle", "open"): "connected", ("connected", "data"): "data_transfer", ("data_transfer", "close"): "closing", ("closing", "ack"): "closed"]
    let finalState = stateMachine(initialState: initial, transitions: transitions, inputSequence: data)
    if finalState != "closed" {
        fatalError("Network connection did not terminate properly")
    }
}

processNetworkData(data: ["open", "data", "close", "ack"])