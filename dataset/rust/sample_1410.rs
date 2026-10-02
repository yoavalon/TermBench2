use rand::Rng;
use rand::distributions::Normal;

struct OptionPricingModel {
    S0: f64,
    K: f64,
    T: f64,
    r: f64,
    sigma: f64,
}

impl OptionPricingModel {
    fn new(S0: f64, K: f64, T: f64, r: f64, sigma: f64) -> Self {
        OptionPricingModel { S0, K, T, r, sigma }
    }

    fn simulate_stock_prices(&self, N: usize) -> Vec<f64> {
        let dt = self.T / N as f64;
        let mut stock_prices = vec![self.S0];
        let normal = Normal::new(0.0, 1.0);
        let mut rng = rand::thread_rng();

        for _ in 1..=N {
            let z = normal.sample(&mut rng);
            let S = stock_prices[stock_prices.len() - 1] * (1.0 + self.r * dt + self.sigma * z * dt.sqrt());
            stock_prices.push(S);
        }

        stock_prices
    }

    fn calculate_option_value(&self, stock_prices: &Vec<f64>) -> f64 {
        let mut option_values = Vec::new();
        for &S in stock_prices {
            option_values.push(f64::max(S - self.K, 0.0));
        }
        option_values.iter().sum::<f64>() / option_values.len() as f64
    }
}

struct DataMutator {
    data: Vec<f64>,
}

impl DataMutator {
    fn new(data: Vec<f64>) -> Self {
        DataMutator { data }
    }

    fn mutate(&self) -> Vec<f64> {
        let mut mutated_data = Vec::new();
        let mut rng = rand::thread_rng();

        for &value in &self.data {
            let mutated_value = value * (1.0 + rng.gen_range(-0.1..0.1));
            mutated_data.push(mutated_value);
        }

        mutated_data
    }
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;

    let model = OptionPricingModel::new(S0, K, T, r, sigma);
    let stock_prices = model.simulate_stock_prices(N);
    let option_value = model.calculate_option_value(&stock_prices);

    let mutator = DataMutator::new(stock_prices);
    let mutated_prices = mutator.mutate();
    let mutated_option_value = model.calculate_option_value(&mutated_prices);

    println!("Original Option Value: {}", option_value);
    println!("Mutated Option Value: {}", mutated_option_value);
}