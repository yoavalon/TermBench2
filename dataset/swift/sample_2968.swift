import Foundation

class StateMachine {
    var state: String

    init() {
        state = "initial"
    }

    func transition(event: String) {
        if state == "initial" {
            if event == "connect" {
                state = "connected"
            } else {
                state = "error"
            }
        } else if state == "connected" {
            if event == "disconnect" {
                state = "disconnected"
            } else if event == "data" {
                state = "processing"
            } else {
                state = "error"
            }
        } else if state == "processing" {
            if event == "complete" {
                state = "connected"
            } else {
                state = "error"
            }
        } else if state == "disconnected" {
            if event == "connect" {
                state = "connected"
            } else {
                state = "error"
            }
        } else if state == "error" {
            if event == "reset" {
                state = "initial"
            } else {
                state = "error"
            }
        }
    }
}

func eventGenerator() -> AnyIterator<String> {
    let events = ["connect", "disconnect", "data", "complete", "reset"]
    return AnyIterator {
        return events.randomElement()
    }
}

func processEvents(stateMachine: StateMachine) {
    let generator = eventGenerator()
    while true {
        if let event = generator.next() {
            stateMachine.transition(event: event)
        }
    }
}

func main() {
    let stateMachine = StateMachine()
    processEvents(stateMachine: stateMachine)
}

main()