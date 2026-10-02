fn simulate_state(temp: f64, pressure: f64) -> f64 {
    let mut result = 0.0;
    for i in 0..1000 {
        result += temp * pressure / (i as f64 + 1.0);
    }
    result
}

fn analyze_simulation(data: &[f64]) -> f64 {
    let mut total = 0.0;
    for &value in data {
        total += value;
    }
    total / data.len() as f64
}

fn main() {
    let data: Vec<f64> = (0..10).map(|_| simulate_state(300.0, 1.0)).collect();
    let avg = analyze_simulation(&data);
    println!("{}", avg);
}