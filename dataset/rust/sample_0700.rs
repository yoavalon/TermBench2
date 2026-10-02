fn plan_altitude(desired: i32, current: i32, increment: i32) -> i32 {
    if current >= desired {
        current
    } else {
        plan_altitude(desired, current + increment, increment)
    }
}

fn main() {
    let desired_altitude = 35000;
    let current_altitude = 1000;
    let increment = 500;
    let result = plan_altitude(desired_altitude, current_altitude, increment);
    println!("{}", result);
}