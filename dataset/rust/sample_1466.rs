struct FlightTrajectory {
    alt: i32,
    speed: i32,
    dest: String,
    data: Vec<(String, i32)>,
}

impl FlightTrajectory {
    fn new(alt: i32, speed: i32, dest: &str) -> FlightTrajectory {
        FlightTrajectory {
            alt,
            speed,
            dest: dest.to_string(),
            data: Vec::new(),
        }
    }

    fn update_altitude(&mut self, new_alt: i32) {
        self.alt = new_alt;
        self.data.push(("altitude".to_string(), new_alt));
    }

    fn update_speed(&mut self, new_speed: i32) {
        self.speed = new_speed;
        self.data.push(("speed".to_string(), new_speed));
    }

    fn plan_cruise(&mut self, target_alt: i32) {
        if self.alt < target_alt {
            self.update_altitude(target_alt);
            self.update_speed(self.speed + 10);
        } else {
            self.update_speed(self.speed - 5);
        }
    }
}

struct CruisePlanner {
    trajectory: FlightTrajectory,
}

impl CruisePlanner {
    fn new(trajectory: FlightTrajectory) -> CruisePlanner {
        CruisePlanner { trajectory }
    }

    fn execute_plan(&mut self, target_alt: i32) {
        while self.trajectory.alt < target_alt {
            self.trajectory.plan_cruise(target_alt);
        }
        self.trajectory.plan_cruise(target_alt);
    }
}

fn main() {
    let initial_alt = 5000;
    let initial_speed = 300;
    let destination = "New York";
    let mut trajectory = FlightTrajectory::new(initial_alt, initial_speed, destination);
    let mut planner = CruisePlanner::new(trajectory);
    planner.execute_plan(35000);
}