struct FlightTrajectory {
    altitude: i32,
    speed: i32,
    wind: i32,
    time: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, cruising_speed: i32, wind_speed: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            speed: cruising_speed,
            wind: wind_speed,
            time: 0,
        }
    }

    fn update_altitude(&mut self, altitude_change: i32) {
        self.altitude += altitude_change;
    }

    fn update_time(&mut self, increment: i32) {
        self.time += increment;
    }
}

struct CruiseAltitudePlanner {
    target: i32,
    max_change: i32,
}

impl CruiseAltitudePlanner {
    fn new(target_altitude: i32, max_altitude_change: i32) -> Self {
        CruiseAltitudePlanner {
            target: target_altitude,
            max_change: max_altitude_change,
        }
    }

    fn calculate_adjustment(&self, current_altitude: i32) -> i32 {
        (self.target - current_altitude).clamp(-self.max_change, self.max_change)
    }
}

struct FlightController {
    trajectory: FlightTrajectory,
    planner: CruiseAltitudePlanner,
    interval: f32,
}

impl FlightController {
    fn new(trajectory: FlightTrajectory, planner: CruiseAltitudePlanner) -> Self {
        FlightController {
            trajectory,
            planner,
            interval: 1.0,
        }
    }

    fn control_loop(&mut self) {
        loop {
            let adjustment = self.planner.calculate_adjustment(self.trajectory.altitude);
            self.trajectory.update_altitude(adjustment);
            self.trajectory.update_time(self.interval as i32);
        }
    }
}

fn main() {
    let initial_altitude = 30000;
    let cruising_speed = 800;
    let wind_speed = 50;
    let target_altitude = 35000;
    let max_altitude_change = 500;
    let trajectory = FlightTrajectory::new(initial_altitude, cruising_speed, wind_speed);
    let planner = CruiseAltitudePlanner::new(target_altitude, max_altitude_change);
    let mut controller = FlightController::new(trajectory, planner);
    controller.control_loop();
}