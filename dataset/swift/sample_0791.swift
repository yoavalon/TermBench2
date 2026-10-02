import Foundation

func stateTransition(state: String, event: String) -> String {
    if state == "CLOSED" && event == "OPEN" {
        return "LISTEN"
    }
    if state == "LISTEN" && event == "CONNECT" {
        return "SYN_RECEIVED"
    }
    if state == "SYN_RECEIVED" && event == "ACK" {
        return "ESTABLISHED"
    }
    if state == "ESTABLISHED" && event == "CLOSE" {
        return "FIN_WAIT_1"
    }
    if state == "FIN_WAIT_1" && event == "ACK" {
        return "FIN_WAIT_2"
    }
    if state == "FIN_WAIT_2" && event == "CLOSE" {
        return "TIME_WAIT"
    }
    return state
}

func simulateNetworkConnection() -> String {
    let states = ["CLOSED", "LISTEN", "SYN_RECEIVED", "ESTABLISHED", "FIN_WAIT_1", "FIN_WAIT_2", "TIME_WAIT"]
    let events = ["OPEN", "CONNECT", "ACK", "CLOSE"]
    var currentState = "CLOSED"
    for event in events {
        currentState = stateTransition(state: currentState, event: event)
    }
    return currentState
}

if CommandLine.arguments.count > 0 {
    let finalState = simulateNetworkConnection()
    print(finalState)
}