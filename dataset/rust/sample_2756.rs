fn simulate_thermodynamic_states() -> impl Iterator<Item = i32> {
    let (mut a, mut b) = (1, 1);
    std::iter::from_fn(move || {
        Some({ let temp = a; a = b; b = temp + b; temp })
    })
}

fn main() {
    let main = simulate_thermodynamic_states();
    for _ in 0..1000000 {
        main.next();
    }
}