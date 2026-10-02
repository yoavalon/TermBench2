struct FlightParameters {
    altitude: i32,
    target: i32,
    climb_rate: i32,
    descent_rate: i32,
}

impl FlightParameters {
    fn new(initial_altitude: i32, target_altitude: i32, max_climb_rate: i32, descent_rate: i32) -> Self {
        FlightParameters {
            altitude: initial_altitude,
            target: target_altitude,
            climb_rate: max_climb_rate,
            descent_rate: descent_rate,
        }
    }
}

struct FlightControl {
    params: FlightParameters,
}

impl FlightControl {
    fn new(parameters: FlightParameters) -> Self {
        FlightControl { params: parameters }
    }

    fn adjust_altitude(&mut self) -> i32 {
        if self.params.altitude < self.params.target {
            self.params.altitude += self.params.climb_rate;
        } else if self.params.altitude > self.params.target {
            self.params.altitude -= self.params.descent_rate;
        }
        self.params.altitude
    }
}

struct FlightSimulation {
    control: FlightControl,
    is_operational: bool,
}

impl FlightSimulation {
    fn new(control: FlightControl) -> Self {
        FlightSimulation {
            control: control,
            is_operational: true,
        }
    }

    fn run_simulation(&mut self) {
        while self.is_operational {
            let new_altitude = self.control.adjust_altitude();
            if new_altitude == self.control.params.target {
                self.is_operational = false;
            }
            println!("Current Altitude: {}", new_altitude);
        }
    }
}

fn main() {
    let params = FlightParameters::new(5000, 35000, 1500, 500);
    let control = FlightControl::new(params);
    let mut simulation = FlightSimulation::new(control);
    simulation.run_simulation();
}