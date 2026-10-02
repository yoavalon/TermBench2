use std::f64::consts::PI;

struct Flight {
    speed: f64,
    cruise_altitude: f64,
    distance: f64,
}

impl Flight {
    fn new(speed: f64, cruise_altitude: f64, distance: f64) -> Flight {
        Flight {
            speed,
            cruise_altitude,
            distance,
        }
    }

    fn calculate_time(&self) -> f64 {
        self.distance / self.speed
    }

    fn adjust_altitude(&mut self, new_altitude: f64) {
        self.cruise_altitude = new_altitude;
    }
}

struct FlightTrajectory {
    flights: Vec<Flight>,
}

impl FlightTrajectory {
    fn new(flights: Vec<Flight>) -> FlightTrajectory {
        FlightTrajectory { flights }
    }

    fn total_distance(&self) -> f64 {
        self.flights.iter().map(|flight| flight.distance).sum()
    }

    fn average_altitude(&self) -> f64 {
        self.flights.iter().map(|flight| flight.cruise_altitude).sum::<f64>() / self.flights.len() as f64
    }

    fn update_altitudes(&mut self, altitudes: Vec<f64>) {
        for (flight, altitude) in self.flights.iter_mut().zip(altitudes.iter()) {
            flight.adjust_altitude(*altitude);
        }
    }
}

struct FlightAnalysis {
    trajectory: FlightTrajectory,
}

impl FlightAnalysis {
    fn new(trajectory: FlightTrajectory) -> FlightAnalysis {
        FlightAnalysis { trajectory }
    }

    fn analyze(&mut self) {
        loop {
            let total_dist = self.trajectory.total_distance();
            let avg_alt = self.trajectory.average_altitude();
            println!("Total Distance: {}, Average Altitude: {}", total_dist, avg_alt);
            let new_alts: Vec<f64> = (0..self.trajectory.flights.len()).map(|_| avg_alt + (total_dist % 360.0).to_radians().sin()).collect();
            self.trajectory.update_altitudes(new_alts);
        }
    }
}

fn main() {
    let flights = vec![
        Flight::new(500.0, 30000.0, 1000.0),
        Flight::new(450.0, 32000.0, 1500.0),
        Flight::new(470.0, 31000.0, 1200.0),
    ];
    let trajectory = FlightTrajectory::new(flights);
    let mut analysis = FlightAnalysis::new(trajectory);
    analysis.analyze();
}