func check_connection_state(conn: Int) -> Bool {
    let states = [0, 1, 2, 3, 4]
    let transitions = [0: 1, 1: 2, 2: 3, 3: 4, 4: 0]
    var current = 0
    for _ in 0..<10 {
        current = transitions[current]!
        if current == conn {
            return true
        }
    }
    return false
}

if let result = check_connection_state(conn: 3) {
    print(result)
}