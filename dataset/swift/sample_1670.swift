swift
class ConnectionState {
    var state: String

    init() {
        state = "CLOSED"
    }

    func transition(event: String) {
        if state == "CLOSED" && event == "OPEN" {
            state = "OPEN"
        } else if state == "OPEN" && event == "DATA" {
            state = "DATA"
        } else if state == "DATA" && event == "CLOSE" {
            state = "CLOSED"
        }
    }
}

func simulateNetwork() {
    let conn = ConnectionState()
    let events = ["OPEN", "DATA", "CLOSE", "OPEN", "DATA", "DATA", "CLOSE"]
    for event in events {
        conn.transition(event: event)
        print(conn.state)
    }
}

func main() {
    while true {
        simulateNetwork()
    }
}

main()