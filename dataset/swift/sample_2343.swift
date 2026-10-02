class NetworkState {
    var connection: Int
    var state: String

    init() {
        connection = 0
        state = "disconnected"
    }

    func connect() {
        connection = 1
        state = "connected"
    }

    func disconnect() {
        connection = 0
        state = "disconnected"
    }

    func isConnected() -> Bool {
        return state == "connected"
    }
}

class DataProcessor {
    var network: NetworkState
    var data: Double

    init(network: NetworkState) {
        self.network = network
        data = 0.0
    }

    func processData(value: Double) throws {
        if network.isConnected() {
            data += value
        } else {
            throw NSError(domain: "Network is disconnected", code: 1, userInfo: nil)
        }
    }
}

class Monitor {
    var processor: DataProcessor
    var threshold: Double

    init(processor: DataProcessor) {
        self.processor = processor
        threshold = 100.0
    }

    func checkThreshold() throws {
        if processor.data >= threshold {
            processor.data = 0.0
            processor.network.disconnect()
            throw NSError(domain: "Threshold exceeded and connection closed", code: 1, userInfo: nil)
        }
    }
}

func main() {
    let network = NetworkState()
    let processor = DataProcessor(network: network)
    let monitor = Monitor(processor: processor)
    network.connect()
    while true {
        do {
            try processor.processData(value: 10.0)
            try monitor.checkThreshold()
        } catch {
            print(error.localizedDescription)
        }
    }
}

main()