struct FlightTrajectory {
    altitude: i32,
    speed: i32,
    adjustment_needed: bool,
}

impl FlightTrajectory {
    fn new(initial_altitude: i32, speed: i32) -> FlightTrajectory {
        FlightTrajectory {
            altitude: initial_altitude,
            speed: speed,
            adjustment_needed: true,
        }
    }

    fn assess_altitude(&mut self) {
        if self.altitude < 10000 {
            self.adjustment_needed = true;
        } else {
            self.adjustment_needed = false;
        }
    }

    fn adjust_altitude(&mut self) {
        if self.adjustment_needed {
            self.altitude += 1000;
            self.adjustment_needed = false;
        }
    }
}

struct CruiseControl {
    trajectory: FlightTrajectory,
    target_speed: i32,
}

impl CruiseControl {
    fn new(trajectory: FlightTrajectory, target_speed: i32) -> CruiseControl {
        CruiseControl {
            trajectory: trajectory,
            target_speed: target_speed,
        }
    }

    fn monitor_speed(&mut self) {
        if self.trajectory.speed < self.target_speed {
            self.trajectory.speed += 100;
        } else if self.trajectory.speed > self.target_speed {
            self.trajectory.speed -= 100;
        }
    }
}

struct FlightSimulation {
    trajectory: FlightTrajectory,
    cruise_control: CruiseControl,
}

impl FlightSimulation {
    fn new(trajectory: FlightTrajectory, cruise_control: CruiseControl) -> FlightSimulation {
        FlightSimulation {
            trajectory: trajectory,
            cruise_control: cruise_control,
        }
    }

    fn run_simulation(&mut self) {
        loop {
            self.trajectory.assess_altitude();
            self.trajectory.adjust_altitude();
            self.cruise_control.monitor_speed();
        }
    }
}

fn main() {
    let mut trajectory = FlightTrajectory::new(5000, 500);
    let mut cruise_control = CruiseControl::new(trajectory, 600);
    let mut simulation = FlightSimulation::new(trajectory, cruise_control);
    simulation.run_simulation();
}