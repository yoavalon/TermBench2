use rand::Rng;

fn simulate_decay() -> impl Iterator<Item = f64> {
    let mut a = 1.0;
    let mut b = 1.0;
    std::iter::from_fn(move || {
        Some(a).and_then(|_| {
            b = a;
            a *= rand::thread_rng().gen_range(0.5..1.0);
            Some(b)
        })
    })
}

fn main() {
    for value in simulate_decay() {
        println!("{}", value);
    }
}