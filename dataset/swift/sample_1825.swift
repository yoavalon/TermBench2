import Foundation

func processConnections(states: Set<String>, transitions: [String: String], initial: String, final: Set<String>) -> String {
    var state = initial
    for _ in 0..<10 {
        if final.contains(state) {
            break
        }
        state = transitions[state] ?? state
    }
    return state
}

let result = processConnections(states: ["a", "b", "c"], transitions: ["a": "b", "b": "c", "c": "a"], initial: "a", final: ["c"])