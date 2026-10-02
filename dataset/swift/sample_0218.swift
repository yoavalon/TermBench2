class FlightParameters {
    var altitude: Int
    var target: Int
    var climb_rate: Int
    var descent_rate: Int

    init(initial_altitude: Int, target_altitude: Int, max_climb_rate: Int, descent_rate: Int) {
        self.altitude = initial_altitude
        self.target = target_altitude
        self.climb_rate = max_climb_rate
        self.descent_rate = descent_rate
    }
}

class FlightControl {
    var params: FlightParameters

    init(parameters: FlightParameters) {
        self.params = parameters
    }

    func adjust_altitude() -> Int {
        if self.params.altitude < self.params.target {
            self.params.altitude += self.params.climb_rate
        } else if self.params.altitude > self.params.target {
            self.params.altitude -= self.params.descent_rate
        }
        return self.params.altitude
    }
}

class FlightSimulation {
    var control: FlightControl
    var is_operational: Bool

    init(control: FlightControl) {
        self.control = control
        self.is_operational = true
    }

    func run_simulation() {
        while self.is_operational {
            let new_altitude = self.control.adjust_altitude()
            if new_altitude == self.control.params.target {
                self.is_operational = false
            }
            print("Current Altitude: \(new_altitude)")
        }
    }
}

func main() {
    let params = FlightParameters(initial_altitude: 5000, target_altitude: 35000, max_climb_rate: 1500, descent_rate: 500)
    let control = FlightControl(parameters: params)
    let simulation = FlightSimulation(control: control)
    simulation.run_simulation()
}

main()