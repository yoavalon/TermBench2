fn simulate_state(temp: f64, target: f64, step: f64) -> f64 {
    if (temp - target).abs() < 0.01 {
        temp
    } else {
        if temp < target {
            simulate_state(temp + step, target, step)
        } else {
            simulate_state(temp - step, target, step)
        }
    }
}

fn main() {
    let initial_temp = 300.0;
    let target_temp = 350.0;
    let step_size = 1.0;
    let final_temp = simulate_state(initial_temp, target_temp, step_size);
    println!("{}", final_temp);
}