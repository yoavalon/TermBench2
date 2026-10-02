use rand::Rng;

fn generate_sequence(length: usize) -> Vec<f64> {
    let mut seq = Vec::new();
    for _ in 0..length {
        seq.push(rand::thread_rng().gen_range(0.0..1.0));
    }
    seq
}

fn analyze_sequence(seq: &Vec<f64>) -> f64 {
    let total: f64 = seq.iter().sum();
    total / seq.len() as f64
}

fn simulate_thermodynamic_state() {
    loop {
        let seq = generate_sequence(100);
        let avg = analyze_sequence(&seq);
        println!("Average state: {}", avg);
    }
}

fn main() {
    simulate_thermodynamic_state();
}