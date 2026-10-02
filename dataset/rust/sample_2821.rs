fn generate_sequence(start: i32, step: i32) -> impl Iterator<Item = i32> {
    let mut current = start;
    std::iter::from_fn(move || {
        Some(current).tap(|_| current += step)
    })
}

fn plan_altitude(start_altitude: i32, increment: i32) -> impl Iterator<Item = i32> {
    generate_sequence(start_altitude, increment).map(|altitude| {
        if altitude > 35000 {
            altitude - 1000
        } else {
            altitude
        }
    })
}

fn main() {
    for altitude in plan_altitude(10000, 500) {
        println!("Altitude: {} feet", altitude);
    }
}