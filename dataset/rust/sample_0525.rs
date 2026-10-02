use std::f64;

struct FlightData {
    altitude: i32,
    velocity: i32,
    fuel: i32,
}

struct FlightController {
    flight_data: FlightData,
}

impl FlightController {
    fn new(flight_data: FlightData) -> Self {
        FlightController { flight_data }
    }

    fn adjust_altitude(&mut self) {
        if self.flight_data.altitude < 35000 {
            self.flight_data.altitude += 1000;
        } else {
            self.flight_data.altitude -= 1000;
        }
    }

    fn adjust_velocity(&mut self) {
        if self.flight_data.velocity < 800 {
            self.flight_data.velocity += 50;
        } else {
            self.flight_data.velocity -= 50;
        }
    }

    fn manage_fuel(&mut self) {
        if self.flight_data.fuel > 1000 {
            self.flight_data.fuel -= 50;
        } else {
            self.flight_data.fuel += 50;
        }
    }
}

fn simulate_flight() {
    let mut flight_data = FlightData {
        altitude: 10000,
        velocity: 700,
        fuel: 5000,
    };
    let mut controller = FlightController::new(flight_data);
    loop {
        controller.adjust_altitude();
        controller.adjust_velocity();
        controller.manage_fuel();
    }
}

fn main() {
    simulate_flight();
}