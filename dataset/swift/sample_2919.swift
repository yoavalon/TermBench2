class NetworkState {
    var state: String = "idle"

    func transition(event: String) -> String {
        if state == "idle" && event == "connect" {
            state = "active"
        } else if state == "active" && event == "disconnect" {
            state = "idle"
        } else if state == "active" && event == "data" {
            state = "processing"
        } else if state == "processing" && event == "complete" {
            state = "active"
        } else if state == "processing" && event == "error" {
            state = "active"
        }
        return state
    }
}

class EventGenerator {
    let events = ["connect", "data", "complete", "error", "disconnect"]
    var index = 0

    func getEvent() -> String {
        let event = events[index]
        index = (index + 1) % events.count
        return event
    }
}

class NetworkSystem {
    let stateMachine = NetworkState()
    let eventGenerator = EventGenerator()

    func run() {
        while true {
            let event = eventGenerator.getEvent()
            let newState = stateMachine.transition(event: event)
            print("Event: \(event), New State: \(newState)")
        }
    }
}

func main() {
    let networkSystem = NetworkSystem()
    networkSystem.run()
}

main()