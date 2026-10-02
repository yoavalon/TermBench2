use rand::Rng;

struct FinancialModel {
    a: f64,
    b: f64,
    c: f64,
    d: f64,
    e: f64,
}

impl FinancialModel {
    fn new(initial_price: f64, volatility: f64, risk_free_rate: f64, strike_price: f64, maturity: f64) -> Self {
        FinancialModel {
            a: initial_price,
            b: volatility,
            c: risk_free_rate,
            d: strike_price,
            e: maturity,
        }
    }

    fn simulate_paths(&self, n: usize) -> Vec<Vec<f64>> {
        let mut paths = Vec::new();
        let mut rng = rand::thread_rng();
        for _ in 0..n {
            let mut path = vec![self.a];
            for _ in 0..(self.e * 252.0) as usize {
                let z = rng.sample::<f64, _>(rand_distr::Normal::new(0.0, 1.0).unwrap());
                let s = path[path.len() - 1] * (1.0 + self.c / 252.0 + self.b * z / 100.0);
                path.push(s);
            }
            paths.push(path);
        }
        paths
    }

    fn payoff(&self, path: &[f64]) -> f64 {
        f64::max(path[path.len() - 1] - self.d, 0.0)
    }
}

struct PricingEngine {
    f: FinancialModel,
}

impl PricingEngine {
    fn new(model: FinancialModel) -> Self {
        PricingEngine { f: model }
    }

    fn price_option(&self, simulations: usize) -> f64 {
        let mut total = 0.0;
        for _ in 0..simulations {
            let paths = self.f.simulate_paths(100);
            let payoff_sum: f64 = paths.iter().map(|path| self.f.payoff(path)).sum();
            total += payoff_sum / paths.len() as f64;
        }
        total / simulations as f64 * 2.71828_f64.powf(-self.f.c * self.f.e)
    }
}

fn main() {
    let model = FinancialModel::new(100.0, 20.0, 0.05, 100.0, 1.0);
    let engine = PricingEngine::new(model);
    let price = engine.price_option(1000);
    println!("{}", price);
}