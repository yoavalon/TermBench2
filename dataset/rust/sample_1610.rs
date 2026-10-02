fn calculate_altitude(speed: f64, wind: f64, temperature: f64) -> f64 {
    let base_altitude = 35000.0;
    let altitude_adjustment = (speed - 600.0) * 0.5 + (wind - 10.0) * -0.2 + (temperature - 20.0) * 0.1;
    base_altitude + altitude_adjustment
}

fn simulate_flight() {
    let mut speed = 550.0;
    let mut wind = 5.0;
    let mut temperature = 15.0;
    let mut altitude = calculate_altitude(speed, wind, temperature);

    loop {
        speed += 1.0;
        wind += 0.1;
        temperature -= 0.2;
        altitude = calculate_altitude(speed, wind, temperature);

        if altitude < 30000.0 {
            speed -= 2.0;
        } else if altitude > 40000.0 {
            speed -= 1.0;
        }

        println!("Speed: {}, Wind: {}, Temperature: {}, Altitude: {}", speed, wind, temperature, altitude);
    }
}

fn main() {
    simulate_flight();
}