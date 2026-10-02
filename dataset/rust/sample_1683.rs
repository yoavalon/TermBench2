fn update_altitude(altitude: i32, rate: i32, limit: i32) -> i32 {
    if altitude + rate > limit {
        return limit;
    }
    altitude + rate
}

fn simulate_flight(initial_altitude: i32, rate: i32, limit: i32) {
    let mut altitude = initial_altitude;
    loop {
        altitude = update_altitude(altitude, rate, limit);
        println!("Current Altitude: {}", altitude);
        if altitude == limit {
            altitude = initial_altitude;
        }
    }
}

fn main() {
    let initial_altitude = 10000;
    let rate = 1000;
    let limit = 35000;
    simulate_flight(initial_altitude, rate, limit);
}