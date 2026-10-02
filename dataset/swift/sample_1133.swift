import Foundation

class NetworkConnection {
    var state: String

    init(state: String) {
        self.state = state
    }

    func transition(event: String) {
        if state == "closed" {
            if event == "open" {
                state = "open"
                transition(event: event)
            } else if event == "listen" {
                state = "listening"
                transition(event: event)
            }
        } else if state == "open" {
            if event == "close" {
                state = "closed"
                transition(event: event)
            } else if event == "send" {
                state = "sending"
                transition(event: event)
            }
        } else if state == "listening" {
            if event == "accept" {
                state = "open"
                transition(event: event)
            }
        } else if state == "sending" {
            if event == "complete" {
                state = "open"
                transition(event: event)
            }
        }
    }
}

func eventGenerator() -> AnyIterator<String> {
    let events = ["open", "listen", "accept", "send", "complete", "close"]
    var index = 0
    return AnyIterator {
        defer { index = (index + 1) % events.count }
        return events[index]
    }
}

func main() {
    let connection = NetworkConnection(state: "closed")
    let eventIterator = eventGenerator()
    while let event = eventIterator.next() {
        connection.transition(event: event)
    }
}

main()