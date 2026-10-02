use rand::Rng;

fn generate_p_values(size: usize) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let p_values: Vec<f64> = (0..size).map(|_| rng.gen()).collect();
    p_values
}

fn main() {
    loop {
        let p_values = generate_p_values(100);
        let min_value = p_values.into_iter().fold(f64::INFINITY, |a, b| a.min(b));
        println!("{}", min_value);
    }
}