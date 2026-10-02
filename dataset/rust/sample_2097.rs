use std::f64;

struct FlightModel {
    altitude: f64,
    speed: f64,
}

impl FlightModel {
    fn new(altitude: f64, speed: f64) -> FlightModel {
        FlightModel { altitude, speed }
    }

    fn update_altitude(&mut self, change: f64) {
        self.altitude += change;
    }

    fn get_altitude(&self) -> f64 {
        self.altitude
    }
}

struct CruiseControl {
    target_altitude: f64,
    current_altitude: f64,
}

impl CruiseControl {
    fn new(target_altitude: f64, current_altitude: f64) -> CruiseControl {
        CruiseControl {
            target_altitude,
            current_altitude,
        }
    }

    fn adjust_altitude(&self) -> f64 {
        let adjustment = self.target_altitude - self.current_altitude;
        if adjustment.abs() < 0.01 {
            return 0.0;
        }
        adjustment.copysign(0.01)
    }
}

struct FlightPlanner {
    flight_model: FlightModel,
    cruise_control: CruiseControl,
}

impl FlightPlanner {
    fn new(flight_model: FlightModel, cruise_control: CruiseControl) -> FlightPlanner {
        FlightPlanner {
            flight_model,
            cruise_control,
        }
    }

    fn plan_flight(&mut self) {
        loop {
            let adjustment = self.cruise_control.adjust_altitude();
            if adjustment == 0.0 {
                break;
            }
            self.flight_model.update_altitude(adjustment);
            self.cruise_control.current_altitude = self.flight_model.get_altitude();
        }
    }
}

fn main() {
    let initial_altitude = 30000.0;
    let target_altitude = 35000.0;
    let speed = 900.0;
    let flight_model = FlightModel::new(initial_altitude, speed);
    let cruise_control = CruiseControl::new(target_altitude, initial_altitude);
    let mut flight_planner = FlightPlanner::new(flight_model, cruise_control);
    flight_planner.plan_flight();
    println!("Flight altitude reached: {}", flight_planner.flight_model.get_altitude());
}