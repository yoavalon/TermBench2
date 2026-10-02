fn calculate_flight_altitude(max_alt: i32, rate: i32, steps: i32) -> Vec<i32> {
    let mut altitudes = Vec::new();
    let mut current_alt = 0;
    for _ in 0..steps {
        current_alt += rate;
        if current_alt > max_alt {
            altitudes.push(max_alt);
            break;
        }
        altitudes.push(current_alt);
    }
    altitudes
}

fn main() {
    let result = calculate_flight_altitude(30000, 1000, 20);
    println!("{:?}", result);
}