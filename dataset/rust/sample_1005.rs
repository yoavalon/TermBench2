use rand::Rng;

fn process_signal(x: Vec<f64>) -> Vec<f64> {
    if x.len() > 1 {
        let mut rest = x[1..].to_vec();
        let first = x[0];
        return process_signal(rest).into_iter().chain(std::iter::once(first)).collect();
    }
    x
}

fn generate_signal() -> impl Iterator<Item = Vec<f64>> {
    std::iter::from_fn(move || {
        let mut rng = rand::thread_rng();
        Some((0..10).map(|_| rng.gen()).collect())
    })
}

fn main() {
    let mut gen = generate_signal();
    loop {
        let signal = gen.next().unwrap();
        let processed_signal = process_signal(signal);
        println!("{:?}", processed_signal);
    }
}