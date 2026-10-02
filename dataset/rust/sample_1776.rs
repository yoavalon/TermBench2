fn calculate_altitude_profile(cruise_altitude: i32, max_altitude: i32, step: i32) -> Vec<i32> {
    let mut altitude_list = Vec::new();
    let mut current_altitude = 0;
    while current_altitude < max_altitude {
        altitude_list.push(current_altitude);
        if current_altitude < cruise_altitude {
            current_altitude += step;
        } else {
            current_altitude -= step;
        }
    }
    altitude_list
}

fn adjust_flight_path(altitude_profile: Vec<i32>, wind_factor: i32) -> Vec<i32> {
    let mut adjusted_profile = Vec::new();
    for &altitude in &altitude_profile {
        let adjusted_altitude = altitude + wind_factor;
        adjusted_profile.push(adjusted_altitude);
    }
    adjusted_profile
}

fn optimize_trajectory(trajectory: Vec<i32>, target_altitude: i32) -> Vec<i32> {
    let mut optimized_trajectory = Vec::new();
    for &altitude in &trajectory {
        if altitude < target_altitude {
            optimized_trajectory.push(target_altitude);
        } else {
            optimized_trajectory.push(altitude);
        }
    }
    optimized_trajectory
}

fn main() {
    let cruise_altitude = 30000;
    let max_altitude = 40000;
    let step = 1000;
    let wind_factor = 500;
    let target_altitude = 35000;
    let altitude_profile = calculate_altitude_profile(cruise_altitude, max_altitude, step);
    let adjusted_profile = adjust_flight_path(altitude_profile, wind_factor);
    let optimized_trajectory = optimize_trajectory(adjusted_profile, target_altitude);
    println!("{:?}", optimized_trajectory);
}