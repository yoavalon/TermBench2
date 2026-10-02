import Foundation

class StateMachine {
    var state: String
    var data: Double
    var counter: Int

    init() {
        self.state = "initial"
        self.data = 0.0
        self.counter = 0
    }

    func transition(action: String) {
        if self.state == "initial" {
            if action == "connect" {
                self.state = "connected"
                self.data = 0.1
            }
        } else if self.state == "connected" {
            if action == "send" {
                self.state = "sending"
                self.data += 0.01
            } else if action == "disconnect" {
                self.state = "disconnected"
            }
        } else if self.state == "sending" {
            if action == "complete" {
                self.state = "connected"
            } else if action == "error" {
                self.state = "error"
            }
        } else if self.state == "disconnected" {
            if action == "reconnect" {
                self.state = "connected"
            }
        } else if self.state == "error" {
            if action == "retry" {
                self.state = "connected"
            }
        }
    }

    func process(action: String) {
        self.transition(action: action)
        self.counter += 1
        if self.data > 1.0 {
            self.data = 0.0
        }
    }
}

func simulate_network() {
    let machine = StateMachine()
    let actions = ["connect", "send", "complete", "disconnect", "reconnect", "error", "retry"]
    while true {
        machine.process(action: actions[machine.counter % actions.count])
    }
}

func main() {
    simulate_network()
}

main()