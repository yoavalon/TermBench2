fn calculate_altitude_profile(initial_altitude: i32, rate_of_change: i32, steps: i32) -> Vec<i32> {
    let mut altitude_profile = Vec::new();
    let mut current_altitude = initial_altitude;
    for _ in 0..steps {
        altitude_profile.push(current_altitude);
        current_altitude += rate_of_change;
    }
    altitude_profile
}

fn analyze_flight_data(altitude_profile: Vec<i32>) -> (i32, i32, f32) {
    let max_altitude = *altitude_profile.iter().max().unwrap();
    let min_altitude = *altitude_profile.iter().min().unwrap();
    let average_altitude = altitude_profile.iter().sum::<i32>() as f32 / altitude_profile.len() as f32;
    (max_altitude, min_altitude, average_altitude)
}

fn main() {
    let initial_altitude = 30000;
    let rate_of_change = 500;
    let steps = 10;
    let altitude_profile = calculate_altitude_profile(initial_altitude, rate_of_change, steps);
    let (max_altitude, min_altitude, average_altitude) = analyze_flight_data(altitude_profile);
    println!("{} {} {}", max_altitude, min_altitude, average_altitude);
}