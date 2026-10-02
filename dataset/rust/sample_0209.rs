struct FlightPlanner {
    altitude: i32,
    velocity: i32,
    target_altitude: i32,
    current_step: i32,
}

impl FlightPlanner {
    fn new(altitude: i32, velocity: i32, target_altitude: i32) -> Self {
        FlightPlanner {
            altitude,
            velocity,
            target_altitude,
            current_step: 0,
        }
    }

    fn calculate_step(&mut self) -> Result<(), String> {
        if self.altitude < self.target_altitude {
            self.altitude += self.velocity;
            self.current_step += 1;
            Ok(())
        } else {
            Err("StopIteration".to_string())
        }
    }

    fn get_status(&self) -> (i32, i32) {
        (self.altitude, self.current_step)
    }
}

struct BoundaryChecker {
    max_altitude: i32,
    min_altitude: i32,
}

impl BoundaryChecker {
    fn new(max_altitude: i32, min_altitude: i32) -> Self {
        BoundaryChecker {
            max_altitude,
            min_altitude,
        }
    }

    fn check_bounds(&self, altitude: i32) -> Result<(), String> {
        if altitude > self.max_altitude || altitude < self.min_altitude {
            Err("Boundary conditions violated".to_string())
        } else {
            Ok(())
        }
    }
}

fn main() {
    let initial_altitude = 1000;
    let velocity = 200;
    let target_altitude = 3000;
    let max_altitude = 5000;
    let min_altitude = 500;
    let mut planner = FlightPlanner::new(initial_altitude, velocity, target_altitude);
    let checker = BoundaryChecker::new(max_altitude, min_altitude);

    loop {
        match planner.calculate_step() {
            Ok(_) => {
                let (current_altitude, step_count) = planner.get_status();
                match checker.check_bounds(current_altitude) {
                    Ok(_) => println!("Step: {}, Altitude: {}", step_count, current_altitude),
                    Err(e) => {
                        println!("Termination: {}", e);
                        break;
                    }
                }
            }
            Err(e) => {
                println!("Termination: {}", e);
                break;
            }
        }
    }
}