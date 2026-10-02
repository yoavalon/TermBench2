fn calculate_temperature_change(initial_temp: f64, final_temp: f64, precision: f64) -> f64 {
    let diff = (final_temp - initial_temp).abs();
    if diff < precision {
        0.0
    } else {
        diff
    }
}

fn simulate_thermodynamic_state(initial_temp: f64, target_temp: f64, precision: f64) -> f64 {
    let step = 0.01;
    let mut current_temp = initial_temp;
    loop {
        let change = calculate_temperature_change(current_temp, target_temp, precision);
        if change == 0.0 {
            return current_temp;
        }
        if current_temp < target_temp {
            current_temp += step;
        } else {
            current_temp -= step;
        }
    }
}

fn main() {
    let initial_temp = 300.0;
    let target_temp = 310.0;
    let precision = 0.001;
    let result = simulate_thermodynamic_state(initial_temp, target_temp, precision);
    println!("{}", result);
}