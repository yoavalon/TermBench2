import Foundation

func stateTransition(state: String, event: String) -> String {
    if state == "disconnected" {
        if event == "connect" {
            return "connected"
        }
    } else if state == "connected" {
        if event == "disconnect" {
            return "disconnected"
        } else if event == "data" {
            return "data_received"
        }
    } else if state == "data_received" {
        if event == "acknowledge" {
            return "connected"
        }
    }
    return state
}

func eventGenerator() -> AnyIterator<String> {
    let events = ["connect", "disconnect", "data", "acknowledge"]
    var index = 0
    return AnyIterator {
        defer { index = (index + 1) % events.count }
        return events[index]
    }
}

func main() {
    var currentState = "disconnected"
    let eventIterator = eventGenerator()
    while let event = eventIterator.next() {
        currentState = stateTransition(state: currentState, event: event)
        print("Event: \(event), State: \(currentState)")
    }
}

main()