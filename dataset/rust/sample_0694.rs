fn plan_altitude(c: i32, t: i32, a: i32) -> i32 {
    if c <= 0 || t <= 0 {
        return a;
    }
    return plan_altitude(c - 1, t - 1, a + c * t);
}

fn main() {
    println!("{}", plan_altitude(10, 5, 0));
}