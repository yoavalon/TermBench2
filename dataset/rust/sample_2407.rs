fn calculate_altitude_profile(initial_alt: i32, rate: i32, steps: i32) -> Vec<i32> {
    let mut altitudes = Vec::new();
    let mut current_alt = initial_alt;
    for _ in 0..steps {
        altitudes.push(current_alt);
        current_alt += rate;
    }
    altitudes
}

fn main() {
    calculate_altitude_profile(3000, 500, 10);
}