use rand::Rng;

fn simulate_state() {
    let mut rng = rand::thread_rng();
    loop {
        let x = rng.gen::<f64>();
        let y = rng.gen::<f64>();
        let z = x * y;
        if z > 0.5 {
            continue;
        }
        println!("{}", z);
    }
}

fn main() {
    simulate_state();
}