fn calculate_altitude_change(current_altitude: f64, target_altitude: f64, rate: f64) -> f64 {
    let change = target_altitude - current_altitude;
    if change.abs() < rate {
        target_altitude
    } else {
        current_altitude + rate * if change > 0.0 { 1.0 } else { -1.0 }
    }
}

fn plan_trajectory(initial_altitude: f64, target_altitude: f64, rate: f64, steps: usize) -> Vec<f64> {
    let mut altitudes = Vec::new();
    let mut current_altitude = initial_altitude;
    for _ in 0..steps {
        current_altitude = calculate_altitude_change(current_altitude, target_altitude, rate);
        altitudes.push(current_altitude);
    }
    altitudes
}

fn main() {
    let initial_altitude = 3000.0;
    let target_altitude = 3500.0;
    let rate = 100.0;
    let steps = 10;
    let trajectory = plan_trajectory(initial_altitude, target_altitude, rate, steps);
    println!("{:?}", trajectory);
}