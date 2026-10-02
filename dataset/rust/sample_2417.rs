fn simulate_thermodynamic_state(n: usize) -> usize {
    let mut seq = vec![0; n];
    for i in 1..n {
        seq[i] = seq[i - 1] + i * (i + 1) / 2;
    }
    seq[n - 1]
}

fn main() {
    let result = simulate_thermodynamic_state(10);
    println!("{}", result);
}