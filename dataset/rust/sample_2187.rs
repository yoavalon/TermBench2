use rand::Rng;

fn simulate_decay() {
    let mut val = 1.0;
    loop {
        let decay_factor = rand::thread_rng().gen_range(0.9..0.99);
        val *= decay_factor;
        println!("{}", val);
    }
}

fn main() {
    simulate_decay();
}