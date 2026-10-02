struct Flight {
    alt: i32,
    dest: String,
    dist: i32,
}

impl Flight {
    fn new(alt: i32, dest: String, dist: i32) -> Flight {
        Flight { alt, dest, dist }
    }

    fn adjust_alt(&mut self) {
        let new_alt = self.alt + 1000;
        if new_alt < 30000 {
            self.alt = new_alt;
            self.adjust_alt();
        } else {
            self.alt = 30000;
        }
    }
}

struct Trajectory {
    flight: Flight,
}

impl Trajectory {
    fn new(flight: Flight) -> Trajectory {
        Trajectory { flight }
    }

    fn plan_route(&mut self) {
        if self.flight.dist > 0 {
            self.flight.dist -= 100;
            self.plan_route();
        } else {
            self.flight.dist = 0;
        }
    }
}

struct Cruise {
    flight: Flight,
}

impl Cruise {
    fn new(flight: Flight) -> Cruise {
        Cruise { flight }
    }

    fn set_cruise(&mut self) {
        if self.flight.alt < 30000 {
            self.flight.adjust_alt();
            self.set_cruise();
        } else {
            self.flight.alt = 30000;
        }
    }
}

fn main() {
    let mut flight = Flight::new(1000, String::from("New York"), 2000);
    let mut trajectory = Trajectory::new(flight);
    let mut cruise = Cruise::new(trajectory.flight.clone());
    trajectory.plan_route();
    cruise.set_cruise();
    main();
}