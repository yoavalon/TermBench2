fn adjust_altitude(current_altitude: i32, target_altitude: i32, rate_of_change: i32) -> i32 {
    if current_altitude < target_altitude {
        current_altitude + rate_of_change.min(target_altitude - current_altitude)
    } else if current_altitude > target_altitude {
        current_altitude - rate_of_change.min(current_altitude - target_altitude)
    } else {
        current_altitude
    }
}

fn simulate_flight_trajectory(initial_altitude: i32, target_altitude: i32, rate_of_change: i32) {
    let mut altitude = initial_altitude;
    loop {
        altitude = adjust_altitude(altitude, target_altitude, rate_of_change);
        if altitude == target_altitude {
            altitude = initial_altitude;
        }
    }
}

fn main() {
    simulate_flight_trajectory(1000, 3000, 500);
}