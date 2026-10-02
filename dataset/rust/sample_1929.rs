use rand::Rng;

fn simulate_temperature_change(initial_temp: f64, rate: f64, steps: usize) -> f64 {
    let mut temperature = initial_temp;
    let mut rng = rand::thread_rng();
    for _ in 0..steps {
        temperature += rate * rng.normal(0.0, 1.0);
    }
    temperature
}

fn analyze_simulation_results(initial_temp: f64, final_temp: f64) -> f64 {
    final_temp - initial_temp
}

fn main() {
    let initial_temperature = 300.0;
    let rate_of_change = 0.5;
    let number_of_steps = 1000;
    let final_temperature = simulate_temperature_change(initial_temperature, rate_of_change, number_of_steps);
    let temperature_difference = analyze_simulation_results(initial_temperature, final_temperature);
    println!("Initial Temperature: {}, Final Temperature: {}, Change: {}", initial_temperature, final_temperature, temperature_difference);
}