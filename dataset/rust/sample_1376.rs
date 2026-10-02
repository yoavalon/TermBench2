fn calculate_altitude(cruise_speed: i32, distance: i32, wind_speed: i32, wind_direction: &str) -> f64 {
    let speed = if wind_direction == "against" {
        cruise_speed - wind_speed
    } else {
        cruise_speed + wind_speed
    };
    let time = distance as f64 / speed as f64;
    let altitude = cruise_speed as f64 * time / 10.0;
    altitude
}

fn adjust_altitude(mut altitude: f64, adjustments: &[i32]) -> f64 {
    for &adjustment in adjustments {
        if adjustment > 0 {
            altitude += adjustment as f64;
        } else {
            altitude -= adjustment.abs() as f64;
        }
    }
    altitude
}

fn main() {
    let cruise_speed = 800;
    let distance = 2000;
    let wind_speed = 50;
    let wind_direction = "against";
    let adjustments = [100, -50, 30];
    let initial_altitude = calculate_altitude(cruise_speed, distance, wind_speed, wind_direction);
    let final_altitude = adjust_altitude(initial_altitude, &adjustments);
    println!("{}", final_altitude);
}