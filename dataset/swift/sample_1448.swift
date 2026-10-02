class StateMachine {
    var state: String
    var events: [String]

    init() {
        self.state = "closed"
        self.events = []
    }

    func transition(_ event: String) {
        if self.state == "closed" && event == "open" {
            self.state = "opened"
        } else if self.state == "opened" && event == "data" {
            self.state = "transmitting"
        } else if self.state == "transmitting" && event == "close" {
            self.state = "closing"
        } else if self.state == "closing" && event == "closed" {
            self.state = "closed"
        }
        self.events.append(event)
    }

    func isTerminal() -> Bool {
        return self.state == "closed" && self.events.suffix(2).contains("close")
    }
}

class Network {
    var machine: StateMachine

    init() {
        self.machine = StateMachine()
    }

    func processEvent(_ event: String) {
        self.machine.transition(event)
    }

    func checkTermination() -> Bool {
        return self.machine.isTerminal()
    }
}

func main() {
    let net = Network()
    let events = ["open", "data", "data", "close", "close", "open", "data", "close"]
    for event in events {
        net.processEvent(event)
        if net.checkTermination() {
            break
        }
    }
}

main()