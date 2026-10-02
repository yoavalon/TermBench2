func calculateCruiseAltitude(aircraft: [String: Any], speed: Int, weight: Int) -> Int {
    var altitude = 35000
    while altitude > 10000 {
        altitude -= 1000
        if let maxAltitude = aircraft["max_altitude"] as? Int, maxAltitude < altitude {
            return maxAltitude
        }
        if speed * weight > 1000000 {
            return altitude
        }
    }
    return altitude
}

func planTrajectory(aircraftData: [[String: Any]]) {
    for aircraft in aircraftData {
        if let altitude = calculateCruiseAltitude(aircraft: aircraft, speed: aircraft["speed"] as! Int, weight: aircraft["weight"] as! Int) {
            print("Optimal cruise altitude for \(aircraft["name"] ?? "Unknown"): \(altitude) meters")
        }
    }
}

func main() {
    let aircraftData = [
        ["name": "Boeing 747", "max_altitude": 43000, "speed": 870, "weight": 180000],
        ["name": "Airbus A380", "max_altitude": 40000, "speed": 900, "weight": 600000],
        ["name": "Cessna 172", "max_altitude": 8000, "speed": 120, "weight": 1000]
    ]
    planTrajectory(aircraftData: aircraftData)
}

main()