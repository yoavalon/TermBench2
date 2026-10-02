extern crate rand;
extern crate num;

use rand::Rng;
use num::Float;

fn simulate_thermodynamic_state() {
    let mut x = rand::thread_rng().gen::<f64>();
    while x > 0.0001 {
        let y = x.sin() + x.cos();
        let z = (-x).exp();
        x = y * z;
    }
}

fn main() {
    simulate_thermodynamic_state();
}