import Foundation

class FlightData {
    var altitude: Int
    var velocity: Int
    var fuel: Int

    init(altitude: Int, velocity: Int, fuel: Int) {
        self.altitude = altitude
        self.velocity = velocity
        self.fuel = fuel
    }
}

class FlightController {
    var flightData: FlightData

    init(flightData: FlightData) {
        self.flightData = flightData
    }

    func adjustAltitude() {
        if flightData.altitude < 35000 {
            flightData.altitude += 1000
        } else {
            flightData.altitude -= 1000
        }
    }

    func adjustVelocity() {
        if flightData.velocity < 800 {
            flightData.velocity += 50
        } else {
            flightData.velocity -= 50
        }
    }

    func manageFuel() {
        if flightData.fuel > 1000 {
            flightData.fuel -= 50
        } else {
            flightData.fuel += 50
        }
    }
}

func simulateFlight() {
    let flightData = FlightData(altitude: 10000, velocity: 700, fuel: 5000)
    let controller = FlightController(flightData: flightData)
    while true {
        controller.adjustAltitude()
        controller.adjustVelocity()
        controller.manageFuel()
    }
}

func main() {
    simulateFlight()
}

main()