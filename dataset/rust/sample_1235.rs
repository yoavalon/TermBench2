use rand::Rng;

fn run() {
    let mut data = Vec::with_capacity(100);
    let mut rng = rand::thread_rng();
    for _ in 0..100 {
        data.push(rng.gen::<f64>());
    }
    let test_stat = data.iter().sum::<f64>() / data.len() as f64;
    let mut p_values = Vec::with_capacity(1000);
    for _ in 0..1000 {
        let count = (0..100).filter(|_| rng.gen::<f64>() < test_stat).count() as f64;
        p_values.push(count / 100.0);
    }
    println!("{}", p_values.iter().cloned().fold(f64::NEG_INFINITY, f64::max));
}

fn main() {
    run();
}