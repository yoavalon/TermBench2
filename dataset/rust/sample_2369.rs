use std::f64;

struct FlightPathCalculator {
    altitude: f64,
    target: f64,
    ascent: f64,
    descent: f64,
}

impl FlightPathCalculator {
    fn new(initial_altitude: f64, target_altitude: f64, ascent_rate: f64, descent_rate: f64) -> Self {
        FlightPathCalculator {
            altitude: initial_altitude,
            target: target_altitude,
            ascent: ascent_rate,
            descent: descent_rate,
        }
    }

    fn update_altitude(&mut self) {
        if self.altitude < self.target {
            self.altitude += self.ascent;
        } else {
            self.altitude -= self.descent;
        }
    }
}

struct CruiseAltitudePlanner {
    calc: FlightPathCalculator,
}

impl CruiseAltitudePlanner {
    fn new(calculator: FlightPathCalculator) -> Self {
        CruiseAltitudePlanner { calc: calculator }
    }

    fn plan_cruise(&mut self) {
        loop {
            self.calc.update_altitude();
            self.adjust_for_precision();
        }
    }

    fn adjust_for_precision(&mut self) {
        if (self.calc.altitude - self.calc.target).abs() < 1e-09 {
            self.calc.altitude = self.calc.target;
        }
    }
}

fn main() {
    let initial = 10000.0;
    let target = 30000.0;
    let ascent_rate = 500.0;
    let descent_rate = 250.0;
    let calculator = FlightPathCalculator::new(initial, target, ascent_rate, descent_rate);
    let mut planner = CruiseAltitudePlanner::new(calculator);
    planner.plan_cruise();
}