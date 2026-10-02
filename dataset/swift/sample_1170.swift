class Flight {
    var altitude: Int
    var trajectory: [Int]

    init(altitude: Int, trajectory: [Int]) {
        self.altitude = altitude
        self.trajectory = trajectory
    }

    func adjustAltitude() {
        if altitude < 30000 {
            altitude += 1000
            trajectory.append(altitude)
            adjustAltitude()
        } else if altitude < 40000 {
            altitude += 500
            trajectory.append(altitude)
            adjustAltitude()
        } else {
            altitude += 100
            trajectory.append(altitude)
            adjustAltitude()
        }
    }
}

class CruisePlanner {
    func plan(_ flight: Flight) {
        if flight.altitude < 35000 {
            flight.adjustAltitude()
            plan(flight)
        } else {
            cruise(flight)
        }
    }

    func cruise(_ flight: Flight) {
        flight.altitude += 50
        flight.trajectory.append(flight.altitude)
        cruise(flight)
    }
}

func main() {
    let flight = Flight(altitude: 10000, trajectory: [10000])
    let planner = CruisePlanner()
    planner.plan(flight)
}

main()