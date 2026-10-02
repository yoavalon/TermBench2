fn calculate_altitude(speed: f64, weight: f64, lift_coefficient: f64) -> f64 {
    let g = 9.81;
    speed.powi(2) * lift_coefficient / (2.0 * g * weight)
}

fn update_speed(speed: f64, drag_coefficient: f64, air_density: f64, area: f64, thrust: f64) -> f64 {
    let drag = 0.5 * air_density * drag_coefficient * area * speed.powi(2);
    let acceleration = (thrust - drag) / 1000.0;
    speed + acceleration
}

fn main() {
    let mut speed = 250.0;
    let weight = 50000.0;
    let lift_coefficient = 0.5;
    let drag_coefficient = 0.045;
    let air_density = 1.225;
    let area = 30.0;
    let thrust = 20000.0;
    loop {
        let altitude = calculate_altitude(speed, weight, lift_coefficient);
        speed = update_speed(speed, drag_coefficient, air_density, area, thrust);
        println!("Altitude: {:.2}m, Speed: {:.2}m/s", altitude, speed);
    }
}