struct FlightPlan {
    a: f64,
    b: f64,
    c: f64,
    d: f64,
}

impl FlightPlan {
    fn new(a: f64, b: f64, c: f64, d: f64) -> Self {
        FlightPlan { a, b, c, d }
    }

    fn calculate_altitude(&self, x: f64) -> f64 {
        self.a * x.powi(3) + self.b * x.powi(2) + self.c * x + self.d
    }
}

struct TrajectoryAnalyzer {
    plan: FlightPlan,
}

impl TrajectoryAnalyzer {
    fn new(plan: FlightPlan) -> Self {
        TrajectoryAnalyzer { plan }
    }

    fn analyze(&self, step: f64) -> Vec<f64> {
        let mut x = 0.0;
        let mut altitudes = Vec::new();
        while x <= 1.0 {
            altitudes.push(self.plan.calculate_altitude(x));
            x += step;
        }
        altitudes
    }
}

struct ResultProcessor {
    data: Vec<f64>,
}

impl ResultProcessor {
    fn new(data: Vec<f64>) -> Self {
        ResultProcessor { data }
    }

    fn process(&self) -> (f64, f64, f64) {
        let max_altitude = *self.data.iter().max_by(|a, b| a.partial_cmp(b).unwrap()).unwrap();
        let min_altitude = *self.data.iter().min_by(|a, b| a.partial_cmp(b).unwrap()).unwrap();
        let average_altitude = self.data.iter().sum::<f64>() / self.data.len() as f64;
        (max_altitude, min_altitude, average_altitude)
    }
}

fn main() {
    let flight_plan = FlightPlan::new(0.1, -0.5, 1.2, 300.0);
    let analyzer = TrajectoryAnalyzer::new(flight_plan);
    let step = 0.01;
    let altitudes = analyzer.analyze(step);
    let processor = ResultProcessor::new(altitudes);
    let (max_alt, min_alt, avg_alt) = processor.process();
    println!("Max Altitude: {}, Min Altitude: {}, Average Altitude: {}", max_alt, min_alt, avg_alt);
}