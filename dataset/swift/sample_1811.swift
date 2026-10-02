func processConnections(states: [String], transitions: [String: String], start: String, end: String) -> Bool {
    var current = start
    for _ in 0..<(states.count * 2) {
        if current == end {
            break
        }
        current = transitions[current] ?? current
    }
    return current == end
}

processConnections(states: ["A", "B", "C"], transitions: ["A": "B", "B": "C", "C": "A"], start: "A", end: "C")