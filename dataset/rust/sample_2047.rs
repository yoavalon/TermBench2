use std::f64::consts::E;

struct FlightPlan {
    distance: f64,
    speed: f64,
    wind: f64,
}

impl FlightPlan {
    fn new(distance: f64, speed: f64, wind: f64) -> Self {
        FlightPlan { distance, speed, wind }
    }

    fn calculate_time(&self) -> f64 {
        let adjusted_speed = self.speed - self.wind;
        self.distance / adjusted_speed
    }
}

struct CruiseAltitude {
    altitude: f64,
    temperature: f64,
}

impl CruiseAltitude {
    fn new(altitude: f64, temperature: f64) -> Self {
        CruiseAltitude { altitude, temperature }
    }

    fn calculate_density(&self) -> f64 {
        let temp_kelvin = self.temperature + 273.15;
        1.225 * E.powf(-0.0065 * self.altitude / temp_kelvin)
    }
}

struct FlightAnalysis {
    flight_plan: FlightPlan,
    cruise_altitude: CruiseAltitude,
}

impl FlightAnalysis {
    fn new(flight_plan: FlightPlan, cruise_altitude: CruiseAltitude) -> Self {
        FlightAnalysis {
            flight_plan,
            cruise_altitude,
        }
    }

    fn analyze(&self) -> (f64, f64) {
        let time = self.flight_plan.calculate_time();
        let density = self.cruise_altitude.calculate_density();
        (time, density)
    }
}

fn main() {
    let flight = FlightPlan::new(1000.0, 500.0, 50.0);
    let altitude = CruiseAltitude::new(10000.0, -50.0);
    let analysis = FlightAnalysis::new(flight, altitude);
    let (time, density) = analysis.analyze();
    println!("Flight Time: {:.2} hours", time);
    println!("Air Density at Cruise Altitude: {:.4} kg/m^3", density);
}