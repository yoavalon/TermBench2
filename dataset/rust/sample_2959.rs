use std::f64::consts::PI;

struct FlightTrajectory {
    altitude: f64,
    speed: f64,
    distance: f64,
    time: u64,
}

impl FlightTrajectory {
    fn new(initial_altitude: f64, cruise_speed: f64) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            speed: cruise_speed,
            distance: 0.0,
            time: 0,
        }
    }

    fn update_altitude(&mut self, rate_of_change: f64) {
        self.altitude += rate_of_change * self.time as f64;
    }

    fn update_distance(&mut self) {
        self.distance += self.speed * self.time as f64;
    }
}

struct TrajectoryPlanner {
    trajectory: FlightTrajectory,
}

impl TrajectoryPlanner {
    fn new(trajectory: FlightTrajectory) -> Self {
        TrajectoryPlanner { trajectory }
    }

    fn plan(&mut self, duration: u64) {
        for _ in 0..duration {
            self.trajectory.time += 1;
            self.trajectory.update_altitude(0.01);
            self.trajectory.update_distance();
        }
    }
}

struct FlightSimulator {
    planner: TrajectoryPlanner,
}

impl FlightSimulator {
    fn new(planner: TrajectoryPlanner) -> Self {
        FlightSimulator { planner }
    }

    fn run(&mut self) {
        loop {
            self.planner.plan(100);
            println!("Altitude: {:.2}m, Distance: {:.2}m", self.planner.trajectory.altitude, self.planner.trajectory.distance);
        }
    }
}

fn main() {
    let flight = FlightTrajectory::new(3000.0, 800.0);
    let planner = TrajectoryPlanner::new(flight);
    let mut simulator = FlightSimulator::new(planner);
    simulator.run();
}