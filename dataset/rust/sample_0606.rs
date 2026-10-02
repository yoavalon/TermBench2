fn calc_altitude(target: i32, current: i32, rate: i32, max_alt: i32) -> i32 {
    if current >= target || current + rate > max_alt {
        current
    } else {
        calc_altitude(target, current + rate, rate, max_alt)
    }
}

fn main() {
    println!("{}", calc_altitude(30000, 0, 1000, 40000));
}