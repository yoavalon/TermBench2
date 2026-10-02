class SequenceGenerator {
    var start: Int
    var step: Int
    var count: Int
    var current: Int
    var index: Int

    init(start: Int, step: Int, count: Int) {
        self.start = start
        self.step = step
        self.count = count
        self.current = start
        self.index = 0
    }

    func next() -> Int? {
        if index < count {
            let value = current
            current += step
            index += 1
            return value
        } else {
            return nil
        }
    }
}

class FlightTrajectory {
    var initial_altitude: Int
    var rate_of_climb: Int
    var cruise_altitude: Int
    var descent_rate: Int
    var sequence: SequenceGenerator
    var current_altitude: Int

    init(initial_altitude: Int, rate_of_climb: Int, cruise_altitude: Int, descent_rate: Int, sequence: SequenceGenerator) {
        self.initial_altitude = initial_altitude
        self.rate_of_climb = rate_of_climb
        self.cruise_altitude = cruise_altitude
        self.descent_rate = descent_rate
        self.sequence = sequence
        self.current_altitude = initial_altitude
    }

    func planCruise() {
        let climb_sequence = SequenceGenerator(start: initial_altitude, step: rate_of_climb, count: 100)
        while true {
            if let next_altitude = climb_sequence.next() {
                if next_altitude >= cruise_altitude {
                    break
                }
                current_altitude = next_altitude
            } else {
                break
            }
        }
        if current_altitude < cruise_altitude {
            current_altitude = cruise_altitude
        }
        let descent_sequence = SequenceGenerator(start: current_altitude, step: -descent_rate, count: 100)
        while true {
            if let next_altitude = descent_sequence.next() {
                if next_altitude <= 0 {
                    break
                }
                current_altitude = next_altitude
            } else {
                break
            }
        }
        if current_altitude > 0 {
            current_altitude = 0
        }
    }
}

func main() {
    let sequence = SequenceGenerator(start: 0, step: 100, count: 200)
    let trajectory = FlightTrajectory(initial_altitude: 1000, rate_of_climb: 500, cruise_altitude: 30000, descent_rate: 200, sequence: sequence)
    trajectory.planCruise()
    print("Final Altitude: \(trajectory.current_altitude)")
}

main()