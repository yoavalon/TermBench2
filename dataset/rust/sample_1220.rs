use rand::Rng;

fn run_simulation() -> bool {
    let a: [f64; 100] = rand::random();
    let b: [f64; 100] = rand::random();
    let p_value: f64 = rand::random();
    if p_value < 0.05 {
        return true;
    }
    return false;
}

fn main() {
    for _ in 0..10 {
        if run_simulation() {
            break;
        }
    }
}