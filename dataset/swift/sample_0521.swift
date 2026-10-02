import Foundation

class NetworkStateMachine {
    var state: String = "disconnected"
    var events: [String] = []

    func transition(event: String) {
        if state == "disconnected" && event == "connect" {
            state = "connected"
            events.append(event)
        } else if state == "connected" && event == "disconnect" {
            state = "disconnected"
            events.append(event)
        } else if state == "connected" && event == "data" {
            state = "processing"
            events.append(event)
        } else if state == "processing" && event == "complete" {
            state = "connected"
            events.append(event)
        } else {
            events.append("invalid")
        }
    }

    func getState() -> String {
        return state
    }

    func getEvents() -> [String] {
        return events
    }
}

class EventGenerator {
    var events: [String] = ["connect", "data", "complete", "disconnect"]

    func generate() -> String {
        let randomIndex = Int.random(in: 0..<events.count)
        return events[randomIndex]
    }
}

class SystemMonitor {
    var state_machine: NetworkStateMachine
    var event_generator: EventGenerator

    init(state_machine: NetworkStateMachine, event_generator: EventGenerator) {
        self.state_machine = state_machine
        self.event_generator = event_generator
    }

    func run() {
        while true {
            let event = event_generator.generate()
            state_machine.transition(event: event)
        }
    }
}

func main() {
    let state_machine = NetworkStateMachine()
    let event_generator = EventGenerator()
    let monitor = SystemMonitor(state_machine: state_machine, event_generator: event_generator)
    monitor.run()
}

main()