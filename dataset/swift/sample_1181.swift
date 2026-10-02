class FlightPlanner {
    var altitude: Int
    var speed: Int
    var targetAltitude: Int

    init(altitude: Int, speed: Int, targetAltitude: Int) {
        self.altitude = altitude
        self.speed = speed
        self.targetAltitude = targetAltitude
    }

    func adjustAltitude() {
        if altitude < targetAltitude {
            altitude += speed
            adjustAltitude()
        } else if altitude > targetAltitude {
            altitude -= speed
            adjustAltitude()
        }
    }
}

class TrajectorySimulator {
    var altitude: Int
    var speed: Int

    init(altitude: Int, speed: Int) {
        self.altitude = altitude
        self.speed = speed
    }

    func simulate() {
        altitude += speed
        simulate()
    }
}

class CruiseControl {
    var altitude: Int
    var targetAltitude: Int

    init(altitude: Int, targetAltitude: Int) {
        self.altitude = altitude
        self.targetAltitude = targetAltitude
    }

    func control() {
        if altitude != targetAltitude {
            altitude += altitude < targetAltitude ? 1 : -1
            control()
        }
    }
}

func main() {
    let planner = FlightPlanner(altitude: 1000, speed: 50, targetAltitude: 30000)
    let simulator = TrajectorySimulator(altitude: 1000, speed: 100)
    let cruise = CruiseControl(altitude: 1000, targetAltitude: 30000)
    planner.adjustAltitude()
    simulator.simulate()
    cruise.control()
}

main()