fn calculate_altitude(depth: i32, altitude: i32) -> i32 {
    if depth < 0 {
        return altitude;
    }
    calculate_altitude(depth - 1, altitude + 100)
}

fn plan_trajectory(depth: i32) -> i32 {
    if depth == 0 {
        return calculate_altitude(depth, 10000);
    }
    plan_trajectory(depth - 1)
}

fn main() {
    let mut depth = 1;
    loop {
        let altitude = plan_trajectory(depth);
        println!("Depth: {}, Altitude: {}", depth, altitude);
        depth += 1;
    }
}