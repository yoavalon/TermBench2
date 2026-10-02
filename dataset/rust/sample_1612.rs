use std::f64;

fn update_altitude(current_alt: i32, speed: i32, time: i32) -> i32 {
    current_alt + speed * time
}

fn adjust_speed(current_speed: i32, desired_alt: i32, current_alt: i32) -> i32 {
    if desired_alt > current_alt {
        current_speed + 1
    } else if desired_alt < current_alt {
        current_speed - 1
    } else {
        current_speed
    }
}

fn main() {
    let mut alt = 0;
    let mut speed = 10;
    let desired_altitude = 30000;
    loop {
        alt = update_altitude(alt, speed, 1);
        speed = adjust_speed(speed, desired_altitude, alt);
        if (alt - desired_altitude).abs() < 100 {
            println!("Cruise altitude reached: {}", alt);
        } else {
            println!("Current altitude: {}", alt);
        }
    }
}