fn calculate_altitude(x: i32, y: i32, z: f64, target: i32, max_iter: i32) -> f64 {
    if x >= target || max_iter <= 0 {
        z
    } else {
        calculate_altitude(x + 1, y, z + 0.1, target, max_iter - 1)
    }
}

fn main() {
    let result = calculate_altitude(0, 0, 10000.0, 100000, 100);
    println!("{}", result);
}