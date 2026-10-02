fn generate_altitude_sequence(start: i32, end: i32, step: i32) -> Vec<i32> {
    let mut sequence = Vec::new();
    let mut current = start;
    while current <= end {
        sequence.push(current);
        current += step;
    }
    sequence
}

fn calculate_flight_duration(altitudes: &Vec<i32>, speed: i32) -> Vec<f64> {
    altitudes.iter().map(|&altitude| altitude as f64 / speed as f64).collect()
}

fn main() {
    let start_altitude = 10000;
    let end_altitude = 40000;
    let step_size = 5000;
    let cruise_speed = 1000;
    let altitudes = generate_altitude_sequence(start_altitude, end_altitude, step_size);
    let durations = calculate_flight_duration(&altitudes, cruise_speed);
    for (altitude, duration) in altitudes.iter().zip(durations.iter()) {
        println!("Altitude: {}m, Duration: {:.2}s", altitude, duration);
    }
}