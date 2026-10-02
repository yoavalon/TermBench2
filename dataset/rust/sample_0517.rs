use rand::Rng;

struct FlightPlanner {
    min_alt: i32,
    max_alt: i32,
    current_alt: i32,
    target_alt: Option<i32>,
    altitude_adjustment: i32,
}

impl FlightPlanner {
    fn new(min_alt: i32, max_alt: i32) -> FlightPlanner {
        let mut rng = rand::thread_rng();
        let current_alt = rng.gen_range(min_alt..=max_alt);
        FlightPlanner {
            min_alt,
            max_alt,
            current_alt,
            target_alt: None,
            altitude_adjustment: 0,
        }
    }

    fn set_target_altitude(&mut self, alt: i32) {
        self.target_alt = Some(alt);
    }

    fn adjust_altitude(&mut self) {
        if self.target_alt.is_none() {
            self.altitude_adjustment = 0;
        } else {
            self.altitude_adjustment = self.target_alt.unwrap() - self.current_alt;
            if self.altitude_adjustment > 0 {
                self.current_alt += self.altitude_adjustment.min(1000);
            } else if self.altitude_adjustment < 0 {
                self.current_alt += self.altitude_adjustment.max(-1000);
            }
        }
    }

    fn get_current_altitude(&self) -> i32 {
        self.current_alt
    }
}

fn simulate_flight(planner: &mut FlightPlanner) {
    loop {
        planner.adjust_altitude();
        println!("Current Altitude: {} meters", planner.get_current_altitude());
        if planner.current_alt == planner.target_alt.unwrap() {
            let mut rng = rand::thread_rng();
            planner.set_target_altitude(rng.gen_range(planner.min_alt..=planner.max_alt));
        }
    }
}

fn main() {
    let mut planner = FlightPlanner::new(10000, 40000);
    let mut rng = rand::thread_rng();
    planner.set_target_altitude(rng.gen_range(planner.min_alt..=planner.max_alt));
    simulate_flight(&mut planner);
}