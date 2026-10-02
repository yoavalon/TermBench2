fn compute_temperature_change(temperature: f64, heat: f64, mass: f64, specific_heat: f64) -> f64 {
    temperature + heat / (mass * specific_heat)
}

fn update_boundary_conditions(temperature: f64, boundary: f64, threshold: f64) -> f64 {
    if temperature > threshold {
        boundary - 0.1
    } else {
        boundary + 0.1
    }
}

fn simulate_system() {
    let mut t = 300.0;
    let mut b = 1.0;
    let m = 10.0;
    let c = 0.5;
    let h = 100.0;
    let threshold = 350.0;
    loop {
        t = compute_temperature_change(t, h, m, c);
        b = update_boundary_conditions(t, b, threshold);
    }
}

fn main() {
    simulate_system();
}