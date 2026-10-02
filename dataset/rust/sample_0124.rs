use std::f64;

fn compute_temperature_change(energy: f64, mass: f64, specific_heat: f64) -> f64 {
    energy / (mass * specific_heat)
}

fn update_boundary_conditions(temp: f64, alpha: f64, dt: f64) -> f64 {
    temp * (1.0 - alpha * dt)
}

fn simulate_thermodynamic_state(initial_temp: f64, energy: f64, mass: f64, specific_heat: f64, alpha: f64, dt: f64, steps: i32) -> f64 {
    let mut temp = initial_temp;
    for _ in 0..steps {
        let delta_temp = compute_temperature_change(energy, mass, specific_heat);
        temp += delta_temp;
        temp = update_boundary_conditions(temp, alpha, dt);
    }
    temp
}

fn main() {
    let initial_temp = 300.0;
    let energy = 1000.0;
    let mass = 50.0;
    let specific_heat = 0.5;
    let alpha = 0.01;
    let dt = 0.1;
    let steps = 100;
    let final_temp = simulate_thermodynamic_state(initial_temp, energy, mass, specific_heat, alpha, dt, steps);
    println!("{}", final_temp);
}