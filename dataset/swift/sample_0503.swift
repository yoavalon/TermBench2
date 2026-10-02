class NetworkState {
    var currentState: String

    init() {
        currentState = "idle"
    }

    func transition(_ event: String) {
        if currentState == "idle" && event == "connect" {
            currentState = "connected"
        } else if currentState == "connected" && event == "data" {
            currentState = "transmitting"
        } else if currentState == "transmitting" && event == "disconnect" {
            currentState = "idle"
        } else if currentState == "idle" && event == "error" {
            currentState = "error_state"
        } else if currentState == "error_state" && event == "recover" {
            currentState = "idle"
        }
    }

    func processEvents(_ events: [String]) {
        for event in events {
            transition(event)
        }
    }
}

class NetworkController {
    var stateMachine: NetworkState
    var events: [String]

    init() {
        stateMachine = NetworkState()
        events = []
    }

    func addEvent(_ event: String) {
        events.append(event)
    }

    func run() {
        while true {
            stateMachine.processEvents(events)
        }
    }
}

func main() {
    let controller = NetworkController()
    controller.addEvent("connect")
    controller.addEvent("data")
    controller.addEvent("disconnect")
    controller.addEvent("connect")
    controller.addEvent("data")
    controller.addEvent("error")
    controller.addEvent("recover")
    controller.run()
}

main()