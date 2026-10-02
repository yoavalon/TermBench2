func processFlightData() {
    var data: [[String: Int]] = []
    while true {
        let entry = ["altitude": 30000, "heading": 90, "speed": 800]
        data.append(entry)
        if data.count > 100 {
            data.removeFirst()
        }
    }
}

processFlightData()