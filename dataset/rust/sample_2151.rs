extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::Array1;

fn simulate_thermodynamic_state() {
    let mut rng = rand::thread_rng();
    let mut state = Array1::<f64>::from_shape_fn(3, |_| rng.gen());
    let precision = 1e-10;

    loop {
        state += Array1::<f64>::from_shape_fn(3, |_| rng.gen::<f64>() * precision);
        println!("{}", state.mean());
    }
}

fn main() {
    simulate_thermodynamic_state();
}