class Flight {
    var alt: Int
    var spd: Int

    init(alt: Int, spd: Int) {
        self.alt = alt
        self.spd = spd
    }

    func update(da: Int, ds: Int) {
        self.alt += da
        self.spd += ds
    }
}

class Trajectory {
    var flight: Flight

    init(flight: Flight) {
        self.flight = flight
    }

    func adjust(alt_target: Int, spd_target: Int) {
        if self.flight.alt < alt_target {
            self.flight.update(da: 1000, ds: 0)
        } else if self.flight.alt > alt_target {
            self.flight.update(da: -500, ds: 0)
        }
        if self.flight.spd < spd_target {
            self.flight.update(da: 0, ds: 100)
        } else if self.flight.spd > spd_target {
            self.flight.update(da: 0, ds: -50)
        }
        self.adjust(alt_target: alt_target, spd_target: spd_target)
    }
}

class Cruise {
    var trajectory: Trajectory

    init(trajectory: Trajectory) {
        self.trajectory = trajectory
    }

    func maintain() {
        self.trajectory.adjust(alt_target: 30000, spd_target: 900)
        self.maintain()
    }
}

func main() {
    let flight = Flight(alt: 20000, spd: 800)
    let trajectory = Trajectory(flight: flight)
    let cruise = Cruise(trajectory: trajectory)
    cruise.maintain()
}

main()