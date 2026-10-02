struct FlightParameters {
    altitude: i32,
    cruise_altitude: i32,
    rate_of_climb: i32,
    rate_of_descent: i32,
}

impl FlightParameters {
    fn new(initial_altitude: i32, cruise_altitude: i32, rate_of_climb: i32, rate_of_descent: i32) -> Self {
        FlightParameters {
            altitude: initial_altitude,
            cruise_altitude: cruise_altitude,
            rate_of_climb: rate_of_climb,
            rate_of_descent: rate_of_descent,
        }
    }

    fn update_altitude(&mut self, action: &str) {
        if action == "climb" {
            self.altitude += self.rate_of_climb;
        } else if action == "descend" {
            self.altitude -= self.rate_of_descent;
        }
    }

    fn is_at_cruise(&self) -> bool {
        self.altitude >= self.cruise_altitude
    }
}

struct BoundaryConditions {
    min_altitude: i32,
    max_altitude: i32,
}

impl BoundaryConditions {
    fn new(min_altitude: i32, max_altitude: i32) -> Self {
        BoundaryConditions {
            min_altitude: min_altitude,
            max_altitude: max_altitude,
        }
    }

    fn is_within_bounds(&self, altitude: i32) -> bool {
        self.min_altitude <= altitude && altitude <= self.max_altitude
    }

    fn adjust_boundary(&self, altitude: i32) -> i32 {
        if altitude < self.min_altitude {
            self.min_altitude
        } else if altitude > self.max_altitude {
            self.max_altitude
        } else {
            altitude
        }
    }
}

fn flight_control_system(flight: &mut FlightParameters, boundaries: &BoundaryConditions) {
    loop {
        if !boundaries.is_within_bounds(flight.altitude) {
            flight.altitude = boundaries.adjust_boundary(flight.altitude);
        }
        if !flight.is_at_cruise() {
            let action = if flight.altitude < flight.cruise_altitude {
                "climb"
            } else {
                "descend"
            };
            flight.update_altitude(action);
        }
    }
}

fn main() {
    let mut flight = FlightParameters::new(5000, 35000, 1000, 500);
    let boundaries = BoundaryConditions::new(5000, 40000);
    flight_control_system(&mut flight, &boundaries);
}