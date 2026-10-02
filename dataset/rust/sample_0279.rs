use rand::distributions::Normal;
use rand::Rng;

struct FinancialModel {
    price: f64,
    volatility: f64,
    strike: f64,
    rate: f64,
    tau: f64,
}

impl FinancialModel {
    fn new(initial_price: f64, volatility: f64, strike_price: f64, risk_free_rate: f64, time_to_maturity: f64) -> Self {
        FinancialModel {
            price: initial_price,
            volatility,
            strike: strike_price,
            rate: risk_free_rate,
            tau: time_to_maturity,
        }
    }

    fn simulate_step(&mut self) {
        let dW: f64 = Normal::new(0.0, 1.0).unwrap().sample(&mut rand::thread_rng());
        let dS = self.price * self.volatility * dW * self.tau.sqrt();
        self.price += dS;
    }

    fn calculate_option_value(&self) -> f64 {
        f64::max(0.0, self.price - self.strike)
    }
}

struct BoundaryConditions {
    lower: f64,
    upper: f64,
    threshold: f64,
    max_steps: usize,
}

impl BoundaryConditions {
    fn new(lower_bound: f64, upper_bound: f64, threshold: f64, max_steps: usize) -> Self {
        BoundaryConditions {
            lower: lower_bound,
            upper: upper_bound,
            threshold,
            max_steps,
        }
    }

    fn check_conditions(&self, price: f64, step_count: usize) -> bool {
        step_count >= self.max_steps || price <= self.lower || price >= self.upper
    }
}

fn main() {
    let initial_price = 100.0;
    let volatility = 0.2;
    let strike_price = 100.0;
    let risk_free_rate = 0.05;
    let time_to_maturity = 1.0;
    let lower_bound = 80.0;
    let upper_bound = 120.0;
    let threshold = 0.01;
    let max_steps = 1000;
    let mut financial_model = FinancialModel::new(initial_price, volatility, strike_price, risk_free_rate, time_to_maturity);
    let boundary_conditions = BoundaryConditions::new(lower_bound, upper_bound, threshold, max_steps);
    let mut step_count = 0;
    while !boundary_conditions.check_conditions(financial_model.price, step_count) {
        financial_model.simulate_step();
        step_count += 1;
    }
    let option_value = financial_model.calculate_option_value();
    println!("Option Value: {}", option_value);
}