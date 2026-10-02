swift
import Foundation

class NetworkStateMachine {
    var state: String
    var data: [String]

    init() {
        self.state = "disconnected"
        self.data = []
    }

    func transition(_ event: String) {
        if self.state == "disconnected" && event == "connect" {
            self.state = "connected"
        } else if self.state == "connected" && event == "send" {
            self.data.append("data")
        } else if self.state == "connected" && event == "disconnect" {
            self.state = "disconnected"
            self.data = []
        }
    }

    func processEvents(_ events: [String]) {
        for event in events {
            self.transition(event)
        }
    }

    func getStatus() -> (String, [String]) {
        return (self.state, self.data)
    }
}

func generateEvents(_ count: Int) -> [String] {
    var events: [String] = []
    for _ in 0..<count {
        let randomNumber = Double.random(in: 0...1)
        if randomNumber < 0.3 {
            events.append("connect")
        } else if randomNumber < 0.5 {
            events.append("send")
        } else {
            events.append("disconnect")
        }
    }
    return events
}

func main() {
    let stateMachine = NetworkStateMachine()
    let events = generateEvents(100)
    stateMachine.processEvents(events)
    let (finalState, finalData) = stateMachine.getStatus()
    print(finalState, finalData)
}

main()