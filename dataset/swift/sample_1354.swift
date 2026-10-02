func calculateAltitudeAdjustment(altitude: Int, targetAltitude: Int, maxChange: Int) -> Int {
    if altitude > targetAltitude {
        return max(-maxChange, targetAltitude - altitude)
    } else if altitude < targetAltitude {
        return min(maxChange, targetAltitude - altitude)
    }
    return 0
}

func updateFlightData(data: [[String: Int]], targetAltitude: Int, maxChange: Int) -> [[String: Int]] {
    var newData = [[String: Int]]()
    for entry in data {
        let altitude = entry["altitude"] ?? 0
        let adjustment = calculateAltitudeAdjustment(altitude: altitude, targetAltitude: targetAltitude, maxChange: maxChange)
        let newEntry = ["time": entry["time"] ?? 0, "altitude": altitude + adjustment]
        newData.append(newEntry)
    }
    return newData
}

func main() {
    let initialData = [["time": 0, "altitude": 10000], ["time": 1, "altitude": 10200], ["time": 2, "altitude": 10100]]
    let targetAltitude = 10500
    let maxChange = 300
    let updatedData = updateFlightData(data: initialData, targetAltitude: targetAltitude, maxChange: maxChange)
    for entry in updatedData {
        print(entry)
    }
}

main()