fn plan_altitude(target: i32, current: i32, step: i32) -> i32 {
    if (target - current).abs() <= step {
        current
    } else if target > current {
        plan_altitude(target, current + step, step)
    } else {
        plan_altitude(target, current - step, step)
    }
}

fn main() {
    println!("{}", plan_altitude(35000, 10000, 5000));
}