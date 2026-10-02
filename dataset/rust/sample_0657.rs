fn plan_altitude(target: i32, current: i32, rate: i32) -> i32 {
    if (target - current).abs() < rate {
        current
    } else {
        plan_altitude(target, current + rate, rate)
    }
}

fn main() {
    let start = 5000;
    let target = 35000;
    let rate = 1000;
    println!("{}", plan_altitude(target, start, rate));
}