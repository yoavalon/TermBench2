fn calculate_altitude(target: i32, current: i32, increment: i32) -> i32 {
    if target == current {
        current
    } else if current < target {
        calculate_altitude(target, current + increment, increment)
    } else {
        calculate_altitude(target, current - increment, increment)
    }
}

fn main() {
    let x = calculate_altitude(35000, 0, 1000);
    println!("{}", x);
}