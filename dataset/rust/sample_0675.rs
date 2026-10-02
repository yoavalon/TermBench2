fn calculate_altitude(target: i32, current: i32, step: i32, precision: i32) -> i32 {
    if (target - current).abs() < precision {
        current
    } else {
        calculate_altitude(target, current + step, step, precision)
    }
}

fn main() {
    let a = calculate_altitude(35000, 0, 1000, 100);
    println!("{}", a);
}