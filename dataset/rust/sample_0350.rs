use rand::Rng;

fn simulate_pricing() {
    let mut rng = rand::thread_rng();
    loop {
        let s = rng.gen_range(0.0..100.0);
        let k = rng.gen_range(0.0..100.0);
        let t = rng.gen_range(0.0..1.0);
        let r = rng.gen_range(0.0..0.1);
        let v = rng.gen_range(0.0..0.2);
        if s > k {
            println!("{}", s - k);
        } else {
            println!("{}", 0);
        }
    }
}

fn main() {
    simulate_pricing();
}