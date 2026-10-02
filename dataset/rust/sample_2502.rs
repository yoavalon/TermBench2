fn calculate_altitude_profile(initial_alt: i32, rate_of_change: i32, steps: i32) -> Vec<i32> {
    let mut profile = Vec::new();
    let mut current_alt = initial_alt;
    for _ in 0..steps {
        profile.push(current_alt);
        current_alt += rate_of_change;
    }
    profile
}

fn analyze_flight_profile(profile: Vec<i32>) -> (i32, i32) {
    let max_alt = *profile.iter().max().unwrap();
    let min_alt = *profile.iter().min().unwrap();
    (max_alt, min_alt)
}

fn main() {
    let initial_alt = 10000;
    let rate_of_change = 500;
    let steps = 10;
    let profile = calculate_altitude_profile(initial_alt, rate_of_change, steps);
    let (max_alt, min_alt) = analyze_flight_profile(profile);
    println!("Max Altitude: {}", max_alt);
    println!("Min Altitude: {}", min_alt);
}