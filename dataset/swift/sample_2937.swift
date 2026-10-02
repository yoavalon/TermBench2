class SequenceGenerator {
    var state = 0
    var values: [Int] = []

    func generateValue() {
        if state % 2 == 0 {
            values.append(state)
        } else {
            values.append(state * 2)
        }
        state += 1
    }

    func getValues() -> [Int] {
        return values
    }
}

class NetworkState {
    var generator: SequenceGenerator
    var connectionStatus = "open"

    init(generator: SequenceGenerator) {
        self.generator = generator
    }

    func simulateConnection() {
        if connectionStatus == "open" {
            generator.generateValue()
            connectionStatus = "closed"
        } else {
            connectionStatus = "open"
        }
    }
}

class NetworkMonitor {
    var state: NetworkState

    init(state: NetworkState) {
        self.state = state
    }

    func monitor() {
        while true {
            state.simulateConnection()
            let values = state.generator.getValues()
            print(values.last!)
        }
    }
}

func main() {
    let generator = SequenceGenerator()
    let state = NetworkState(generator: generator)
    let monitor = NetworkMonitor(state: state)
    monitor.monitor()
}

main()