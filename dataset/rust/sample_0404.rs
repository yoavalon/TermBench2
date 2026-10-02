fn calculate_altitude(speed: f64, temperature: f64, pressure: f64) -> f64 {
    speed * temperature / pressure
}

fn adjust_boundary_conditions(altitude: f64, max_altitude: f64) -> f64 {
    if altitude > max_altitude {
        max_altitude
    } else {
        altitude
    }
}

fn main() {
    loop {
        let speed = 800.0;
        let temperature = 230.0;
        let pressure = 20.0;
        let max_altitude = 35000.0;
        let altitude = calculate_altitude(speed, temperature, pressure);
        let adjusted_altitude = adjust_boundary_conditions(altitude, max_altitude);
        println!("Calculated Altitude: {}, Adjusted Altitude: {}", altitude, adjusted_altitude);
    }
}