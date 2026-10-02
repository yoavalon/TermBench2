class Flight {
    var alt: Int
    var dest: String
    var dist: Int

    init(alt: Int, dest: String, dist: Int) {
        self.alt = alt
        self.dest = dest
        self.dist = dist
    }

    func adjustAlt() {
        let newAlt = alt + 1000
        if newAlt < 30000 {
            alt = newAlt
            adjustAlt()
        } else {
            alt = 30000
        }
    }
}

class Trajectory {
    var flight: Flight

    init(flight: Flight) {
        self.flight = flight
    }

    func planRoute() {
        if flight.dist > 0 {
            flight.dist -= 100
            planRoute()
        } else {
            flight.dist = 0
        }
    }
}

class Cruise {
    var flight: Flight

    init(flight: Flight) {
        self.flight = flight
    }

    func setCruise() {
        if flight.alt < 30000 {
            flight.adjustAlt()
            setCruise()
        } else {
            flight.alt = 30000
        }
    }
}

func main() {
    let flight = Flight(alt: 1000, dest: "New York", dist: 2000)
    let trajectory = Trajectory(flight: flight)
    let cruise = Cruise(flight: flight)
    trajectory.planRoute()
    cruise.setCruise()
    main()
}

main()