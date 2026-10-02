fn calculate_cruise_altitude(speed: f64, temperature: f64) -> f64 {
    let a = 1.0287;
    let b = -10.911;
    let c = 260370.0;
    a * speed + b * temperature + c
}

fn plan_trajectory(altitudes: &[f64], target: f64) -> f64 {
    let total: f64 = altitudes.iter().sum();
    let average = total / altitudes.len() as f64;
    average - target
}

fn main() {
    let speeds = vec![800.5, 900.3, 750.8];
    let temperatures = vec![15.2, 14.8, 16.0];
    let altitudes: Vec<f64> = speeds.iter().zip(temperatures.iter()).map(|(&s, &t)| calculate_cruise_altitude(s, t)).collect();
    let target_altitude = 35000.0;
    let adjustment = plan_trajectory(&altitudes, target_altitude);
    println!("Adjustment needed: {:.2} meters", adjustment);
}