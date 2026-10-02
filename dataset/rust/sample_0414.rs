fn calculate_cruise_altitude(speed: f64, weight: f64, temperature: f64) -> f64 {
    let base_altitude = 30000.0;
    let speed_factor = speed / 900.0;
    let weight_factor = weight / 100000.0;
    let temp_factor = (20.0 - temperature) / 10.0;
    base_altitude + speed_factor * 5000.0 - weight_factor * 3000.0 + temp_factor * 2000.0
}

fn simulate_flight(speed: f64, weight: f64, temperature: f64) {
    loop {
        let altitude = calculate_cruise_altitude(speed, weight, temperature);
        println!("Current Altitude: {} feet", altitude);
        let speed = speed + 10.0;
        let weight = weight - 500.0;
    }
}

fn main() {
    simulate_flight(850.0, 200000.0, 15.0);
}