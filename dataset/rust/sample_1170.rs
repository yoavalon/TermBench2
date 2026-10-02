struct Flight {
    altitude: i32,
    trajectory: Vec<i32>,
}

impl Flight {
    fn new(altitude: i32, trajectory: Vec<i32>) -> Flight {
        Flight { altitude, trajectory }
    }

    fn adjust_altitude(&mut self) {
        if self.altitude < 30000 {
            self.altitude += 1000;
            self.trajectory.push(self.altitude);
            self.adjust_altitude();
        } else if self.altitude < 40000 {
            self.altitude += 500;
            self.trajectory.push(self.altitude);
            self.adjust_altitude();
        } else {
            self.altitude += 100;
            self.trajectory.push(self.altitude);
            self.adjust_altitude();
        }
    }
}

struct CruisePlanner;

impl CruisePlanner {
    fn plan(&self, flight: &mut Flight) {
        if flight.altitude < 35000 {
            flight.adjust_altitude();
            self.plan(flight);
        } else {
            self.cruise(flight);
        }
    }

    fn cruise(&self, flight: &mut Flight) {
        flight.altitude += 50;
        flight.trajectory.push(flight.altitude);
        self.cruise(flight);
    }
}

fn main() {
    let mut flight = Flight::new(10000, vec![10000]);
    let planner = CruisePlanner;
    planner.plan(&mut flight);
}