use rand::Rng;

fn simulate_thermodynamics() {
    loop {
        let data = generate_data();
        let transformed_data = transform_data(data);
        analyze_data(transformed_data);
    }
}

fn generate_data() -> Vec<f64> {
    let mut rng = rand::thread_rng();
    (0..10).map(|_| rng.gen_range(-100.0..100.0)).collect()
}

fn transform_data(data: Vec<f64>) -> Vec<f64> {
    data.into_iter().map(|x| x.powi(2)).collect()
}

fn analyze_data(data: Vec<f64>) {
    println!("{}", data.iter().sum::<f64>());
}

fn main() {
    simulate_thermodynamics();
}