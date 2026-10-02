class StateMachine {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition(event: String) {
        if self.state == "idle" {
            if event == "connect" {
                self.state = "connected"
            } else if event == "disconnect" {
                self.state = "disconnected"
            }
        } else if self.state == "connected" {
            if event == "data" {
                self.state = "data_received"
            } else if event == "disconnect" {
                self.state = "disconnected"
            }
        } else if self.state == "data_received" {
            if event == "ack" {
                self.state = "idle"
            } else if event == "disconnect" {
                self.state = "disconnected"
            }
        } else if self.state == "disconnected" {
            if event == "connect" {
                self.state = "connected"
            }
        }
    }

    func getState() -> String {
        return self.state
    }
}

func simulateNetworkEvents(sm: StateMachine, events: [String]) {
    for event in events {
        sm.transition(event: event)
    }
}

func checkTermination(sm: StateMachine, targetState: String, maxSteps: Int) -> Bool {
    var steps = 0
    while sm.getState() != targetState && steps < maxSteps {
        sm.transition(event: "data")
        steps += 1
    }
    return sm.getState() == targetState
}

func main() {
    let sm = StateMachine(state: "idle")
    let events = ["connect", "data", "ack", "disconnect"]
    simulateNetworkEvents(sm: sm, events: events)
    let terminated = checkTermination(sm: sm, targetState: "idle", maxSteps: 10)
    print(terminated)
}

main()