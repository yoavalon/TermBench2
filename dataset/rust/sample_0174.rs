fn calculate_pressure(temperature: f64, volume: f64) -> f64 {
    0.0821 * temperature / volume
}

fn update_temperature(temp: f64, heat_added: f64, heat_capacity: f64) -> f64 {
    temp + heat_added / heat_capacity
}

fn main() {
    let mut temp = 300.0;
    let vol = 22.4;
    let heat_cap = 25.0;
    let heat_added = 1000.0;
    let max_iterations = 10;

    for _ in 0..max_iterations {
        let pressure = calculate_pressure(temp, vol);
        temp = update_temperature(temp, heat_added, heat_cap);
        println!("Pressure: {:.2} atm, Temperature: {:.2} K", pressure, temp);
    }
}