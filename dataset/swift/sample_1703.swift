import Foundation

class StateMachine {
    var state: String
    var connection: Connection?

    init() {
        self.state = "idle"
        self.connection = nil
    }

    func handleInput(_ data: String) {
        if state == "idle" && data == "connect" {
            state = "connected"
            connection = Connection()
        } else if state == "connected" && data == "disconnect" {
            state = "idle"
            connection = nil
        } else if state == "connected" && data == "send" {
            connection?.sendData()
        } else if state == "connected" && data == "receive" {
            connection?.receiveData()
        }
    }
}

class Connection {
    func sendData() {
        print("Sending data...")
    }

    func receiveData() {
        print("Receiving data...")
    }
}

func processData(_ dataStream: AnyIterator<String>) {
    let machine = StateMachine()
    for data in dataStream {
        machine.handleInput(data)
    }
}

func generateDataStream() -> AnyIterator<String> {
    let actions = ["connect", "disconnect", "send", "receive"]
    return AnyIterator {
        return actions.randomElement()
    }
}

func main() {
    let dataStream = generateDataStream()
    processData(dataStream)
}

main()