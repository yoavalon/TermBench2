use rand::Rng;

fn financial_simulation() {
    let (r, mut s, t, v) = (0.05, 100.0, 1, 0.2);
    let mut rng = rand::thread_rng();
    loop {
        let z = rng.sample::<f64, _>(rand::distributions::StandardNormal);
        s *= 1.0 + r - 0.5 * v.powi(2) + v * z;
        println!("{}", s);
    }
}

fn main() {
    financial_simulation();
}