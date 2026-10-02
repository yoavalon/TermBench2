struct SequenceGenerator {
    start: i32,
    step: i32,
    count: i32,
    current: i32,
    index: i32,
}

impl SequenceGenerator {
    fn new(start: i32, step: i32, count: i32) -> SequenceGenerator {
        SequenceGenerator {
            start,
            step,
            count,
            current: start,
            index: 0,
        }
    }

    fn next(&mut self) -> Option<i32> {
        if self.index < self.count {
            let value = self.current;
            self.current += self.step;
            self.index += 1;
            Some(value)
        } else {
            None
        }
    }
}

struct FlightTrajectory {
    initial_altitude: i32,
    rate_of_climb: i32,
    cruise_altitude: i32,
    descent_rate: i32,
    sequence: SequenceGenerator,
    current_altitude: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, rate_of_climb: i32, cruise_altitude: i32, descent_rate: i32, sequence: SequenceGenerator) -> FlightTrajectory {
        FlightTrajectory {
            initial_altitude,
            rate_of_climb,
            cruise_altitude,
            descent_rate,
            sequence,
            current_altitude: initial_altitude,
        }
    }

    fn plan_cruise(&mut self) {
        let mut climb_sequence = SequenceGenerator::new(self.initial_altitude, self.rate_of_climb, 100);
        while let Some(next_altitude) = climb_sequence.next() {
            if next_altitude >= self.cruise_altitude {
                break;
            }
            self.current_altitude = next_altitude;
        }
        if self.current_altitude < self.cruise_altitude {
            self.current_altitude = self.cruise_altitude;
        }
        let mut descent_sequence = SequenceGenerator::new(self.current_altitude, -self.descent_rate, 100);
        while let Some(next_altitude) = descent_sequence.next() {
            if next_altitude <= 0 {
                break;
            }
            self.current_altitude = next_altitude;
        }
        if self.current_altitude > 0 {
            self.current_altitude = 0;
        }
    }
}

fn main() {
    let sequence = SequenceGenerator::new(0, 100, 200);
    let mut trajectory = FlightTrajectory::new(1000, 500, 30000, 200, sequence);
    trajectory.plan_cruise();
    println!("Final Altitude: {}", trajectory.current_altitude);
}