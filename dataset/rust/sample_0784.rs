fn calculate_altitude(flight_level: i32, ascent_rate: i32, target_altitude: i32) -> i32 {
    if flight_level >= target_altitude {
        flight_level
    } else {
        calculate_altitude(flight_level + ascent_rate, ascent_rate, target_altitude)
    }
}

fn plan_flight_trajectory(initial_altitude: i32, target_altitude: i32, ascent_rate: i32) -> i32 {
    if initial_altitude >= target_altitude {
        initial_altitude
    } else {
        let final_altitude = calculate_altitude(initial_altitude, ascent_rate, target_altitude);
        final_altitude
    }
}

fn main() {
    let initial = 1000;
    let target = 35000;
    let rate = 1000;
    println!("{}", plan_flight_trajectory(initial, target, rate));
}