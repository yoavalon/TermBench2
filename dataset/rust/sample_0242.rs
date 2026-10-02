struct FlightData {
    altitude: i32,
    speed: i32,
    distance: i32,
    max_altitude: i32,
}

impl FlightData {
    fn new(altitude: i32, speed: i32, distance: i32, max_altitude: i32) -> FlightData {
        FlightData {
            altitude,
            speed,
            distance,
            max_altitude,
        }
    }

    fn update_altitude(&mut self, new_altitude: i32) {
        if new_altitude <= self.max_altitude {
            self.altitude = new_altitude;
        } else {
            self.altitude = self.max_altitude;
        }
    }

    fn update_distance(&mut self, new_distance: i32) {
        self.distance = new_distance;
    }
}

struct CruisePlanner {
    flight_data: FlightData,
}

impl CruisePlanner {
    fn new(flight_data: FlightData) -> CruisePlanner {
        CruisePlanner { flight_data }
    }

    fn calculate_cruise_altitude(&self) -> i32 {
        if self.flight_data.speed > 500 {
            i32::min(self.flight_data.altitude + 1000, self.flight_data.max_altitude)
        } else {
            i32::max(self.flight_data.altitude - 1000, 0)
        }
    }

    fn adjust_trajectory(&mut self) {
        let new_altitude = self.calculate_cruise_altitude();
        self.flight_data.update_altitude(new_altitude);
        self.flight_data.update_distance(self.flight_data.distance + 100);
    }
}

fn main() {
    let mut flight_data = FlightData::new(5000, 600, 0, 10000);
    let mut cruise_planner = CruisePlanner::new(flight_data);
    for _ in 0..10 {
        cruise_planner.adjust_trajectory();
    }
    println!("Final Altitude: {}", cruise_planner.flight_data.altitude);
    println!("Final Distance: {}", cruise_planner.flight_data.distance);
}