struct FlightPath {
    altitude: i32,
    target_altitude: i32,
    rate_of_climb: i32,
}

impl FlightPath {
    fn new(start_altitude: i32, target_altitude: i32, rate_of_climb: i32) -> Self {
        FlightPath {
            altitude: start_altitude,
            target_altitude,
            rate_of_climb,
        }
    }

    fn climb(&mut self) {
        self.altitude += self.rate_of_climb;
        if self.altitude > self.target_altitude {
            self.altitude = self.target_altitude;
        }
    }

    fn get_status(&self) -> (i32, i32) {
        (self.altitude, self.target_altitude)
    }
}

struct CruiseAltitude {
    altitude: i32,
    max_speed: i32,
    wind_speed: i32,
}

impl CruiseAltitude {
    fn new(altitude: i32, max_speed: i32, wind_speed: i32) -> Self {
        CruiseAltitude {
            altitude,
            max_speed,
            wind_speed,
        }
    }

    fn adjust_speed(&mut self) {
        self.max_speed = self.max_speed - self.wind_speed / 2;
    }

    fn get_speed(&self) -> i32 {
        self.max_speed
    }
}

fn main() {
    let mut flight = FlightPath::new(1000, 35000, 100);
    let mut cruise = CruiseAltitude::new(35000, 800, 20);
    loop {
        flight.climb();
        cruise.adjust_speed();
        let (current_alt, target_alt) = flight.get_status();
        let current_speed = cruise.get_speed();
        if current_alt == target_alt {
            println!("Reached target altitude: {}", current_alt);
            println!("Cruise speed adjusted to: {}", current_speed);
        } else {
            println!("Current altitude: {}, Target altitude: {}", current_alt, target_alt);
            println!("Current speed: {}", current_speed);
        }
    }
}