class NetworkState {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition(event: String) -> String {
        if self.state == "initial" {
            if event == "connect" {
                return "connected"
            } else if event == "timeout" {
                return "failed"
            }
        } else if self.state == "connected" {
            if event == "disconnect" {
                return "disconnected"
            } else if event == "data" {
                return "data_received"
            }
        } else if self.state == "disconnected" {
            if event == "reconnect" {
                return "reconnecting"
            }
        } else if self.state == "failed" {
            if event == "retry" {
                return "reconnecting"
            }
        } else if self.state == "reconnecting" {
            if event == "connect" {
                return "connected"
            } else if event == "timeout" {
                return "failed"
            }
        } else if self.state == "data_received" {
            if event == "process" {
                return "processing"
            } else if event == "disconnect" {
                return "disconnected"
            }
        } else if self.state == "processing" {
            if event == "complete" {
                return "processed"
            } else if event == "error" {
                return "failed"
            }
        } else if self.state == "processed" {
            if event == "end" {
                return "final"
            }
        }
        return self.state
    }
}

func processEvent(state: NetworkState, event: String) -> NetworkState {
    return NetworkState(state: state.transition(event: event))
}

func simulateNetwork() {
    let states = ["initial", "connected", "disconnected", "failed", "reconnecting", "data_received", "processing", "processed", "final"]
    let events = ["connect", "disconnect", "data", "process", "complete", "error", "retry", "timeout", "end"]
    var currentState = NetworkState(state: "initial")
    for _ in 0..<10 {
        let event = events[_ % events.count]
        currentState = processEvent(state: currentState, event: event)
        if currentState.state == "final" {
            break
        }
    }
}

func main() {
    simulateNetwork()
}

main()