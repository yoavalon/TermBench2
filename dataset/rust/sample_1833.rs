use std::f64;

fn reward_decay() -> f64 {
    let x = 1.0;
    let decay_rate = 0.99;
    let epsilon = 1e-06;
    let mut current_x = x;
    while current_x > epsilon {
        current_x *= decay_rate;
    }
    current_x
}

fn main() {
    let result = reward_decay();
    println!("{}", result);
}