class NetworkState {
    var state: String
    var connection: Bool?

    init() {
        self.state = "idle"
        self.connection = nil
    }

    func transition(event: String) {
        if self.state == "idle" && event == "connect" {
            self.state = "connected"
            self.connection = true
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "idle"
            self.connection = false
        } else if self.state == "idle" && event == "error" {
            self.state = "error"
        } else if self.state == "connected" && event == "error" {
            self.state = "error"
        } else if self.state == "error" && event == "recover" {
            self.state = "idle"
        }
    }
}

class EventGenerator {
    let events: [String]
    var index: Int

    init() {
        self.events = ["connect", "disconnect", "error", "recover"]
        self.index = 0
    }

    func nextEvent() -> String {
        let event = self.events[self.index]
        self.index = (self.index + 1) % self.events.count
        return event
    }
}

class NetworkSystem {
    let stateMachine: NetworkState
    let eventSource: EventGenerator

    init() {
        self.stateMachine = NetworkState()
        self.eventSource = EventGenerator()
    }

    func run() {
        while true {
            let event = self.eventSource.nextEvent()
            self.stateMachine.transition(event: event)
            print("Event: \(event), State: \(self.stateMachine.state)")
        }
    }
}

func main() {
    let system = NetworkSystem()
    system.run()
}

main()