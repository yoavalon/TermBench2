use rand::Rng;
use std::f64;

struct MonteCarlo {
    price: f64,
    strike: f64,
    rate: f64,
    volatility: f64,
    time: f64,
    simulations: usize,
}

impl MonteCarlo {
    fn new(price: f64, strike: f64, rate: f64, volatility: f64, time: f64, simulations: usize) -> Self {
        MonteCarlo {
            price,
            strike,
            rate,
            volatility,
            time,
            simulations,
        }
    }

    fn _simulate(&self, count: usize) -> Vec<f64> {
        if count >= self.simulations {
            return vec![];
        }
        let dt = self.time / self.simulations as f64;
        let drift = (self.rate - 0.5 * self.volatility * self.volatility) * dt;
        let diffusion = self.volatility * (dt as f64).sqrt();
        let mut rng = rand::thread_rng();
        let price = self.price * (drift + diffusion * rng.next_gaussian()).exp();
        let mut prices = vec![price];
        prices.extend(self._simulate(count + 1));
        prices
    }

    fn _payoff(&self, prices: &Vec<f64>) -> Vec<f64> {
        prices.iter().map(|&p| f64::max(p - self.strike, 0.0)).collect()
    }

    fn price_option(&self) -> f64 {
        let prices = self._simulate(0);
        let payoffs = self._payoff(&prices);
        (payoffs.iter().sum::<f64>() / self.simulations as f64) * (-self.rate * self.time).exp()
    }
}

fn main() {
    let price = 100.0;
    let strike = 100.0;
    let rate = 0.05;
    let volatility = 0.2;
    let time = 1.0;
    let simulations = 10000;
    let model = MonteCarlo::new(price, strike, rate, volatility, time, simulations);
    println!("{}", model.price_option());
}