use std::f64::consts::PI;

struct FinancialModel {
    price: f64,
    strike: f64,
    volatility: f64,
    rate: f64,
    time: f64,
}

impl FinancialModel {
    fn new(price: f64, strike: f64, volatility: f64, rate: f64, time: f64) -> Self {
        FinancialModel {
            price,
            strike,
            volatility,
            rate,
            time,
        }
    }

    fn d1(&self) -> f64 {
        (self.price / self.strike).ln() + (self.rate + 0.5 * self.volatility.powi(2)) * self.time
            / (self.volatility * (self.time.sqrt()))
    }

    fn d2(&self) -> f64 {
        self.d1() - self.volatility * (self.time.sqrt())
    }

    fn call_price(&self) -> f64 {
        self.price * (-self.rate * self.time).exp() * self.cdf(self.d1())
            - self.strike * (-self.rate * self.time).exp() * self.cdf(self.d2())
    }

    fn put_price(&self) -> f64 {
        self.strike * (-self.rate * self.time).exp() * self.cdf(-self.d2())
            - self.price * (-self.rate * self.time).exp() * self.cdf(-self.d1())
    }

    fn cdf(&self, x: f64) -> f64 {
        0.5 * (1.0 + (x / 2.0_f64.sqrt()).erf())
    }
}

fn simulate_pricing(model: &FinancialModel, simulations: i32, depth: i32) -> f64 {
    if depth == 0 {
        return 0.0;
    }
    let call_value = model.call_price();
    let put_value = model.put_price();
    call_value + put_value + simulate_pricing(model, simulations, depth - 1)
}

fn main() {
    let model = FinancialModel::new(100.0, 100.0, 0.2, 0.05, 1.0);
    let simulations = 1000;
    let depth = 5;
    let total_value = simulate_pricing(&model, simulations, depth);
    println!("Total Estimated Value: {}", total_value);
}