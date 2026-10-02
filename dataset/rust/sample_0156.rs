fn calculate_cruise_altitude(speed: i32, weight: i32, _conditions: ()) -> i32 {
    let mut altitude = 0;
    if speed > 500 && weight < 10000 {
        altitude = 35000;
    } else if speed > 400 && weight < 8000 {
        altitude = 30000;
    } else {
        altitude = 25000;
    }
    altitude
}

fn adjust_trajectory(altitude: i32, target: i32) -> i32 {
    let difference = target - altitude;
    if difference > 1000 {
        1000
    } else if difference < -1000 {
        -1000
    } else {
        difference
    }
}

fn main() {
    let speed = 550;
    let weight = 9500;
    let target_altitude = 34000;
    let current_altitude = calculate_cruise_altitude(speed, weight, ());
    let adjustment = adjust_trajectory(current_altitude, target_altitude);
    println!("Current Altitude: {}", current_altitude);
    println!("Adjustment Needed: {}", adjustment);
}