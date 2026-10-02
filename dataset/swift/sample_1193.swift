import Foundation

class StateMachine {
    var state: String

    init() {
        self.state = "idle"
    }

    func transition(event: String) {
        if state == "idle" {
            if event == "connect" {
                state = "active"
            } else if event == "error" {
                state = "errored"
            }
        } else if state == "active" {
            if event == "disconnect" {
                state = "idle"
            } else if event == "error" {
                state = "errored"
            }
        } else if state == "errored" {
            if event == "recover" {
                state = "idle"
            }
        }
    }

    func process(eventSequence: [String]) -> [String] {
        var states: [String] = []
        for event in eventSequence {
            transition(event: event)
            states.append(state)
        }
        return states
    }
}

func generateEvents() -> AnyIterator<String> {
    var index = 0
    let events = ["connect", "disconnect", "error", "recover"]
    return AnyIterator {
        let event = events[index % events.count]
        index += 1
        return event
    }
}

func monitor(stateMachine: StateMachine, eventGenerator: AnyIterator<String>) {
    for event in eventGenerator {
        stateMachine.transition(event: event)
        print("Event: \(event), State: \(stateMachine.state)")
    }
}

func main() {
    let stateMachine = StateMachine()
    let eventGenerator = generateEvents()
    monitor(stateMachine: stateMachine, eventGenerator: eventGenerator)
}

main()