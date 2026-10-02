use std::f64;

fn simulate_thermodynamic_state() {
    let mut x = 1.0;
    let mut y = 0.1;
    loop {
        x = x.sqrt();
        y = y.sqrt();
        println!("x: {}, y: {}", x, y);
    }
}

fn main() {
    simulate_thermodynamic_state();
}