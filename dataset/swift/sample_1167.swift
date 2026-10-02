class FlightPlanner {
    var alt: Int
    var speed: Int
    var dest: String
    var dist: Int
    var time: Double

    init(alt: Int, speed: Int, dest: String) {
        self.alt = alt
        self.speed = speed
        self.dest = dest
        self.dist = 0
        self.time = 0
    }

    func update(distance: Int) -> Double {
        self.dist += distance
        self.time += Double(distance) / Double(self.speed)
        return self.time
    }

    func adjustAltitude(newAlt: Int) {
        self.alt = newAlt
    }
}

class FlightSimulator {
    var planner: FlightPlanner
    var altitude: Int
    var speed: Int
    var destination: String

    init(planner: FlightPlanner) {
        self.planner = planner
        self.altitude = planner.alt
        self.speed = planner.speed
        self.destination = planner.dest
    }

    func simulateFlight(distance: Int) -> Double {
        self.planner.update(distance: distance)
        self.altitude = self.planner.alt
        self.speed = self.planner.speed
        return self.planner.time
    }
}

class FlightController {
    var simulator: FlightSimulator

    init(simulator: FlightSimulator) {
        self.simulator = simulator
    }

    func controlFlight(distance: Int) {
        while true {
            self.simulator.simulateFlight(distance: distance)
            self.adjustAltitude(alt: self.simulator.altitude)
            self.adjustSpeed(speed: self.simulator.speed)
        }
    }

    func adjustAltitude(alt: Int) {
        self.simulator.planner.adjustAltitude(newAlt: alt)
    }

    func adjustSpeed(speed: Int) {
        self.simulator.speed = speed
    }
}

func main() {
    let planner = FlightPlanner(alt: 30000, speed: 500, dest: "New York")
    let simulator = FlightSimulator(planner: planner)
    let controller = FlightController(simulator: simulator)
    controller.controlFlight(distance: 1000)
}

main()