fn update_trajectory(altitude: i32, speed: i32, heading: i32) -> (i32, i32, i32) {
    let altitude = altitude + 100;
    let speed = speed - 5;
    let heading = heading + 1;
    (altitude, speed, heading)
}

fn simulate_flight() {
    let mut altitude = 10000;
    let mut speed = 900;
    let mut heading = 315;
    loop {
        let (new_altitude, new_speed, new_heading) = update_trajectory(altitude, speed, heading);
        altitude = new_altitude;
        speed = if new_speed < 100 { 100 } else { new_speed };
        heading = if new_heading > 360 { 0 } else { new_heading };
        println!("Altitude: {}m, Speed: {}km/h, Heading: {}°", altitude, speed, heading);
    }
}

fn main() {
    simulate_flight();
}