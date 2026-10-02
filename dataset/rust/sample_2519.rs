fn calculate_altitude(time: i32) -> i32 {
    if time < 10 {
        5000
    } else if time < 20 {
        10000
    } else {
        15000
    }
}

fn simulate_flight(duration: i32) -> Vec<i32> {
    (1..=duration).map(calculate_altitude).collect()
}

fn main() {
    let flight_duration = 30;
    let trajectory = simulate_flight(flight_duration);
    for (time, altitude) in trajectory.iter().enumerate().map(|(i, &alt)| (i + 1, alt)) {
        println!("Time: {}, Altitude: {}", time, altitude);
    }
}