fn simulate_state(temp: f64, pressure: f64, volume: f64) -> (f64, f64) {
    let internal_energy = temp * volume * pressure;
    let entropy = internal_energy / (temp * pressure);
    (internal_energy, entropy)
}

fn check_boundary_conditions(temp: f64, pressure: f64, volume: f64) -> bool {
    let max_temp = 1000.0;
    let min_pressure = 1.0;
    let max_volume = 1000.0;
    if temp > max_temp || pressure < min_pressure || volume > max_volume {
        false
    } else {
        true
    }
}

fn main() {
    let temp = 500.0;
    let pressure = 2.0;
    let volume = 500.0;
    if check_boundary_conditions(temp, pressure, volume) {
        let (internal_energy, entropy) = simulate_state(temp, pressure, volume);
        println!("Simulation Complete: {} {}", internal_energy, entropy);
    } else {
        println!("Boundary conditions exceeded");
    }
}