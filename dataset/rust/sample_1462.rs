struct FlightData {
    altitude: i32,
    target_altitude: i32,
    rate_of_climb: i32,
}

impl FlightData {
    fn new(initial_altitude: i32, target_altitude: i32, rate_of_climb: i32) -> FlightData {
        FlightData {
            altitude: initial_altitude,
            target_altitude: target_altitude,
            rate_of_climb: rate_of_climb,
        }
    }

    fn update_altitude(&mut self) {
        if self.altitude < self.target_altitude {
            self.altitude += self.rate_of_climb;
        } else {
            self.altitude = self.target_altitude;
        }
    }
}

struct TrajectoryPlanner {
    data: FlightData,
}

impl TrajectoryPlanner {
    fn new(data: FlightData) -> TrajectoryPlanner {
        TrajectoryPlanner { data: data }
    }

    fn plan_trajectory(&mut self) {
        while self.data.altitude < self.data.target_altitude {
            self.data.update_altitude();
            self.adjust_cruise_altitude();
        }
    }

    fn adjust_cruise_altitude(&mut self) {
        if self.data.altitude > 30000 {
            self.data.rate_of_climb = 500;
        } else if self.data.altitude > 20000 {
            self.data.rate_of_climb = 1000;
        } else {
            self.data.rate_of_climb = 1500;
        }
    }
}

fn main() {
    let initial_altitude = 10000;
    let target_altitude = 40000;
    let rate_of_climb = 2000;
    let mut flight_data = FlightData::new(initial_altitude, target_altitude, rate_of_climb);
    let mut trajectory_planner = TrajectoryPlanner::new(flight_data);
    trajectory_planner.plan_trajectory();
    println!("Final Altitude: {}", trajectory_planner.data.altitude);
}