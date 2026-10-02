class FlightPlanner {
    var speed: Double
    var altitude: Double
    var distance: Double

    init(speed: Double, altitude: Double, distance: Double) {
        self.speed = speed
        self.altitude = altitude
        self.distance = distance
    }

    func calculateTime() -> Double {
        return distance / speed
    }

    func adjustAltitude(newAltitude: Double) {
        altitude = newAltitude
    }

    func getCurrentState() -> (Double, Double, Double) {
        return (speed, altitude, distance)
    }
}

class CruiseControl {
    var planner: FlightPlanner

    init(planner: FlightPlanner) {
        self.planner = planner
    }

    func stabilizeAltitude() {
        while true {
            let currentAltitude = planner.altitude
            if currentAltitude < 35000 {
                planner.adjustAltitude(newAltitude: currentAltitude + 1000)
            } else if currentAltitude > 37000 {
                planner.adjustAltitude(newAltitude: currentAltitude - 1000)
            }
        }
    }

    func monitorSpeed() {
        let (speed, _, _) = planner.getCurrentState()
        if speed < 800 {
            planner.speed += 10
        } else if speed > 900 {
            planner.speed -= 10
        }
    }
}

class FlightSimulation {
    var planner: FlightPlanner
    var control: CruiseControl

    init() {
        planner = FlightPlanner(speed: 850, altitude: 36000, distance: 1000000)
        control = CruiseControl(planner: planner)
    }

    func runSimulation() {
        while true {
            control.stabilizeAltitude()
            control.monitorSpeed()
            let time = planner.calculateTime()
            print("Speed: \(planner.speed), Altitude: \(planner.altitude), Time to Destination: \(time, specifier: "%.2f") hours")
        }
    }
}

func main() {
    let simulation = FlightSimulation()
    simulation.runSimulation()
}

main()