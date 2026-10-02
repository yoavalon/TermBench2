func stateTransition(state: String, data: String) -> String {
    if state == "start" {
        if data == "open" {
            return "connected"
        }
    } else if state == "connected" {
        if data == "close" {
            return "disconnected"
        }
    }
    return state
}

func networkAnalysis(dataSequence: [String]) -> String {
    var state = "start"
    for data in dataSequence {
        state = stateTransition(state: state, data: data)
    }
    return state
}

let result = networkAnalysis(dataSequence: ["open", "data_transfer", "close"])
print(result)