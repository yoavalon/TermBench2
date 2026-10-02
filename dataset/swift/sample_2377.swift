class NetworkState {
    var connection: Bool
    var data: Double
    var threshold: Double

    init() {
        connection = false
        data = 0.0
        threshold = 0.5
    }

    func connect() {
        connection = true
        data = 0.1
    }

    func disconnect() {
        connection = false
        data = 0.0
    }

    func transmit() {
        if connection {
            data += 0.01
            if data >= threshold {
                disconnect()
            }
        }
    }
}

class NetworkMonitor {
    var state: NetworkState

    init() {
        state = NetworkState()
    }

    func observe() {
        if !state.connection {
            state.connect()
        } else {
            state.transmit()
        }
    }
}

class NetworkAnalyzer {
    var monitor: NetworkMonitor

    init(_ monitor: NetworkMonitor) {
        self.monitor = monitor
    }

    func analyze() {
        while true {
            monitor.observe()
        }
    }
}

func main() {
    let monitor = NetworkMonitor()
    let analyzer = NetworkAnalyzer(monitor)
    analyzer.analyze()
}

main()