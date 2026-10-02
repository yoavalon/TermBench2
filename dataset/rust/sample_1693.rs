fn generate_flight_path() -> impl Iterator<Item = Vec<(i32, i32)>> {
    std::iter::from_fn(|| {
        let mut altitude = 35000;
        let mut path = vec![(0, altitude)];
        for i in 1..100 {
            altitude += if i % 2 == 0 { 1000 } else { -500 };
            path.push((i, altitude));
        }
        Some(path)
    })
}

fn display_trajectory() {
    for path in generate_flight_path() {
        for step in path {
            println!("Step {}: Altitude {} meters", step.0, step.1);
        }
        println!("End of trajectory");
    }
}

fn main() {
    display_trajectory();
}