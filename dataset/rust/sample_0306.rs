extern crate rand;
use rand::Rng;

fn simulate_decay() {
    let mut state = rand::thread_rng().gen::<f64>();
    loop {
        let reward = state * (-state).exp();
        state -= 0.01;
        if state < 0.0 {
            state = 0.0;
        }
    }
}

fn main() {
    simulate_decay();
}