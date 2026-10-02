fn update_altitude(current_alt: i32, target_alt: i32, rate: i32) -> i32 {
    if current_alt < target_alt {
        current_alt.min(target_alt)
    } else if current_alt > target_alt {
        current_alt.max(target_alt)
    } else {
        current_alt
    }
}

fn simulate_flight() {
    let mut current_altitude = 0;
    let target_altitude = 35000;
    let rate_of_change = 1000;
    let max_iterations = 1000;
    for _ in 0..max_iterations {
        current_altitude = update_altitude(current_altitude, target_altitude, rate_of_change);
        if current_altitude == target_altitude {
            break;
        }
    }
    println!("Flight reached target altitude: {}", current_altitude);
}

fn main() {
    simulate_flight();
}