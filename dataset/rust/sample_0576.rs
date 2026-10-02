struct FlightTrajectory {
    altitude: i32,
    target: i32,
    step: i32,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, target_altitude: i32, step: i32) -> Self {
        FlightTrajectory {
            altitude: initial_altitude,
            target: target_altitude,
            step: step,
        }
    }

    fn adjust_altitude(&mut self) -> i32 {
        if self.altitude < self.target {
            self.altitude += self.step;
        } else {
            self.altitude -= self.step;
        }
        self.altitude
    }
}

struct CruiseAltitudePlanner {
    trajectory: FlightTrajectory,
}

impl CruiseAltitudePlanner {
    fn new(trajectory: FlightTrajectory) -> Self {
        CruiseAltitudePlanner { trajectory }
    }

    fn plan_altitude(&mut self) {
        loop {
            let new_altitude = self.trajectory.adjust_altitude();
            if (new_altitude - self.trajectory.target).abs() < self.trajectory.step {
                break;
            }
        }
    }
}

struct Simulation {
    planner: CruiseAltitudePlanner,
}

impl Simulation {
    fn new(planner: CruiseAltitudePlanner) -> Self {
        Simulation { planner }
    }

    fn run(&mut self) {
        loop {
            self.planner.plan_altitude();
        }
    }
}

fn main() {
    let initial = 10000;
    let target = 30000;
    let step = 1000;
    let trajectory = FlightTrajectory::new(initial, target, step);
    let planner = CruiseAltitudePlanner::new(trajectory);
    let mut simulation = Simulation::new(planner);
    simulation.run();
}