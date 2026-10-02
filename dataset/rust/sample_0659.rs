fn simulate_thermodynamic_state(temp: f64, target_temp: f64, rate: f64, threshold: f64) -> f64 {
    if (temp - target_temp).abs() < threshold {
        temp
    } else {
        let new_temp = temp + rate * (target_temp - temp);
        simulate_thermodynamic_state(new_temp, target_temp, rate, threshold)
    }
}

fn main() {
    let initial_temp = 300.0;
    let target_temp = 373.0;
    let rate = 0.01;
    let threshold = 0.05;
    let result = simulate_thermodynamic_state(initial_temp, target_temp, rate, threshold);
    println!("{}", result);
}