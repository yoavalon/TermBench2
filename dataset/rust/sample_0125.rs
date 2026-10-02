fn calculate_altitude(speed: i32, wind: i32, max_altitude: i32) -> i32 {
    std::cmp::max(0, std::cmp::min(max_altitude, speed - wind))
}

fn update_trajectory(alt: i32, time: i32, descent_rate: i32) -> i32 {
    if alt > 0 {
        alt - descent_rate * time
    } else {
        0
    }
}

fn main() {
    let speed = 600;
    let wind = 50;
    let max_altitude = 30000;
    let descent_rate = 100;
    let time_step = 1;
    let mut current_altitude = calculate_altitude(speed, wind, max_altitude);
    while current_altitude > 0 {
        println!("Current Altitude: {}", current_altitude);
        current_altitude = update_trajectory(current_altitude, time_step, descent_rate);
    }
}