fn calculate_altitude(speed: f64, wind: f64, payload: f64) -> f64 {
    10000.0 + speed * wind / payload
}

fn update_conditions(speed: f64, wind: f64, payload: f64, increment: f64) -> (f64, f64, f64) {
    (speed + increment, wind - increment, payload + increment)
}

fn main() {
    let (mut speed, mut wind, mut payload) = (500.0, 20.0, 1000.0);
    loop {
        let altitude = calculate_altitude(speed, wind, payload);
        (speed, wind, payload) = update_conditions(speed, wind, payload, 10.0);
        println!("Altitude: {}m, Speed: {}km/h, Wind: {}km/h, Payload: {}kg", altitude, speed, wind, payload);
    }
}