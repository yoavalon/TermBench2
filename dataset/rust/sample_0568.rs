struct Flight {
    altitude: i32,
    speed: i32,
    heading: i32,
}

impl Flight {
    fn new(altitude: i32, speed: i32, heading: i32) -> Flight {
        Flight {
            altitude,
            speed,
            heading,
        }
    }

    fn update_altitude(&mut self, new_altitude: i32) {
        self.altitude = new_altitude;
    }

    fn update_speed(&mut self, new_speed: i32) {
        self.speed = new_speed;
    }

    fn update_heading(&mut self, new_heading: i32) {
        self.heading = new_heading;
    }
}

fn boundary_check(flight: &mut Flight, min_alt: i32, max_alt: i32) {
    if flight.altitude < min_alt {
        flight.update_altitude(min_alt);
    } else if flight.altitude > max_alt {
        flight.update_altitude(max_alt);
    }
}

fn cruise_control(flight: &mut Flight, target_speed: i32) {
    if flight.speed < target_speed {
        flight.update_speed(flight.speed + 1);
    } else if flight.speed > target_speed {
        flight.update_speed(flight.speed - 1);
    }
}

fn flight_simulation() {
    let mut flight = Flight::new(10000, 500, 90);
    let min_altitude = 5000;
    let max_altitude = 30000;
    let target_speed = 600;
    loop {
        boundary_check(&mut flight, min_altitude, max_altitude);
        cruise_control(&mut flight, target_speed);
    }
}

fn main() {
    flight_simulation();
}