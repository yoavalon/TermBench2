struct Flight {
    alt: i32,
    spd: i32,
}

impl Flight {
    fn new(alt: i32, spd: i32) -> Flight {
        Flight { alt, spd }
    }

    fn update(&mut self, da: i32, ds: i32) {
        self.alt += da;
        self.spd += ds;
    }
}

struct Trajectory {
    flight: Flight,
}

impl Trajectory {
    fn new(flight: Flight) -> Trajectory {
        Trajectory { flight }
    }

    fn adjust(&mut self, alt_target: i32, spd_target: i32) {
        if self.flight.alt < alt_target {
            self.flight.update(1000, 0);
        } else if self.flight.alt > alt_target {
            self.flight.update(-500, 0);
        }
        if self.flight.spd < spd_target {
            self.flight.update(0, 100);
        } else if self.flight.spd > spd_target {
            self.flight.update(0, -50);
        }
        self.adjust(alt_target, spd_target);
    }
}

struct Cruise {
    trajectory: Trajectory,
}

impl Cruise {
    fn new(trajectory: Trajectory) -> Cruise {
        Cruise { trajectory }
    }

    fn maintain(&mut self) {
        self.trajectory.adjust(30000, 900);
        self.maintain();
    }
}

fn main() {
    let mut flight = Flight::new(20000, 800);
    let mut trajectory = Trajectory::new(flight);
    let mut cruise = Cruise::new(trajectory);
    cruise.maintain();
}