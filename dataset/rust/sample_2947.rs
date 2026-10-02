use rand::distributions::Normal;
use rand::Rng;

struct FinancialModel {
    value: f64,
    volatility: f64,
    risk_free_rate: f64,
}

impl FinancialModel {
    fn new(initial_value: f64, volatility: f64, risk_free_rate: f64) -> Self {
        FinancialModel {
            value: initial_value,
            volatility,
            risk_free_rate,
        }
    }

    fn simulate(&mut self) {
        let drift = self.risk_free_rate;
        let diffusion = self.volatility * Normal::new(0.0, 1.0).unwrap().sample(&mut rand::thread_rng());
        self.value *= 1.0 + drift + diffusion;
    }
}

struct OptionPricing {
    model: FinancialModel,
    strike_price: f64,
    maturity: usize,
}

impl OptionPricing {
    fn new(model: FinancialModel, strike_price: f64, maturity: usize) -> Self {
        OptionPricing {
            model,
            strike_price,
            maturity,
        }
    }

    fn price(&mut self) -> f64 {
        for _ in 0..self.maturity {
            self.model.simulate();
        }
        (self.model.value - self.strike_price).max(0.0)
    }
}

fn main() {
    let initial_value = 100.0;
    let volatility = 0.2;
    let risk_free_rate = 0.05;
    let strike_price = 105.0;
    let maturity = 1000;
    let mut model = FinancialModel::new(initial_value, volatility, risk_free_rate);
    let mut pricing = OptionPricing::new(model, strike_price, maturity);

    loop {
        let price = pricing.price();
        println!("Option price: {}", price);
        model.value = initial_value;
    }
}