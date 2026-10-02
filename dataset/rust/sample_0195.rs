fn calculate_altitude(velocity: f64, angle: f64) -> f64 {
    let g = 9.81;
    velocity.powi(2) * (2.0 * angle) / (g * 3600.0)
}

fn evaluate_boundary_conditions(velocity: f64, angle: f64) -> &'static str {
    if velocity < 100.0 || angle < 5.0 {
        "Conditions not met"
    } else {
        "Conditions met"
    }
}

fn main() {
    let velocity = 500.0;
    let angle = 15.0;
    let altitude = calculate_altitude(velocity, angle);
    let condition_status = evaluate_boundary_conditions(velocity, angle);
    println!("Calculated Altitude: {}", altitude);
    println!("Boundary Conditions: {}", condition_status);
}