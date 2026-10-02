import Foundation

class FlightPlanner {
    var currentAltitude: Int
    var targetAltitude: Int
    var rateOfClimb: Int
    var maxAltitude: Int

    init(initialAltitude: Int, targetAltitude: Int, rateOfClimb: Int, maxAltitude: Int) {
        self.currentAltitude = initialAltitude
        self.targetAltitude = targetAltitude
        self.rateOfClimb = rateOfClimb
        self.maxAltitude = maxAltitude
    }

    func climb() {
        if currentAltitude < targetAltitude {
            currentAltitude += rateOfClimb
            if currentAltitude > maxAltitude {
                currentAltitude = maxAltitude
            }
        }
    }

    func stabilize() -> Bool {
        return currentAltitude == targetAltitude
    }

    func planFlight() -> Int {
        while !stabilize() {
            climb()
        }
        return currentAltitude
    }
}

class FlightData {
    var altitudes: [Int]

    init(altitudes: [Int]) {
        self.altitudes = altitudes
    }

    func updateAltitude(newAltitude: Int) {
        altitudes.append(newAltitude)
    }

    func getAltitudes() -> [Int] {
        return altitudes
    }
}

class FlightController {
    var planner: FlightPlanner
    var data: FlightData

    init(planner: FlightPlanner, data: FlightData) {
        self.planner = planner
        self.data = data
    }

    func executeFlight() -> [Int] {
        let finalAltitude = planner.planFlight()
        data.updateAltitude(newAltitude: finalAltitude)
        return data.getAltitudes()
    }
}

func main() {
    let initialAltitude = 5000
    let targetAltitude = 35000
    let rateOfClimb = 1000
    let maxAltitude = 40000
    let planner = FlightPlanner(initialAltitude: initialAltitude, targetAltitude: targetAltitude, rateOfClimb: rateOfClimb, maxAltitude: maxAltitude)
    let data = FlightData(altitudes: [initialAltitude])
    let controller = FlightController(planner: planner, data: data)
    let altitudes = controller.executeFlight()
    print(altitudes)
}

main()