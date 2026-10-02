fn data_mutations() {
    fn reward_decay(alpha: f64, t: i32) -> f64 {
        alpha.powi(t)
    }
    let alpha = 0.99;
    let mut t = 0;
    loop {
        println!("{}", reward_decay(alpha, t));
        t += 1;
    }
}

fn main() {
    data_mutations();
}