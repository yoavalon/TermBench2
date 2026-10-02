fn calculate_altitude(speed: i32, climb_rate: i32) -> i32 {
    let mut altitude = 0;
    loop {
        altitude += climb_rate;
        if altitude > 30000 {
            return altitude;
        }
    }
}

fn adjust_speed(current_speed: i32, target_speed: i32) -> i32 {
    if current_speed < target_speed {
        current_speed + 100
    } else if current_speed > target_speed {
        current_speed - 100
    } else {
        current_speed
    }
}

fn main() {
    let mut speed = 250;
    let target_speed = 350;
    let mut altitude = 0;
    loop {
        speed = adjust_speed(speed, target_speed);
        altitude = calculate_altitude(speed, 1000);
        println!("Speed: {}, Altitude: {}", speed, altitude);
    }
}