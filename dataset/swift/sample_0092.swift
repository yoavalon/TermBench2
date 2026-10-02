func analyzeNetworkConnections(connections: [String], states: [String], transitions: [(String, String, String)]) -> String {
    var currentState = states[0]
    for connection in connections {
        for transition in transitions {
            if transition.0 == currentState && transition.1 == connection {
                currentState = transition.2
                break
            }
        }
    }
    return currentState
}

let connections = ["open", "data", "close"]
let states = ["idle", "active", "closed"]
let transitions = [("idle", "open", "active"), ("active", "data", "active"), ("active", "close", "closed")]
let result = analyzeNetworkConnections(connections: connections, states: states, transitions: transitions)
print(result)