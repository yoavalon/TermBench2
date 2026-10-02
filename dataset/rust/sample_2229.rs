fn calculate_altitude(time: i32, initial_altitude: i32, rate_of_change: f64) -> f64 {
    initial_altitude as f64 + rate_of_change * time as f64
}

fn adjust_rate(current_altitude: f64, target_altitude: i32, current_rate: f64) -> f64 {
    if current_altitude < target_altitude as f64 {
        current_rate + 0.1
    } else if current_altitude > target_altitude as f64 {
        current_rate - 0.1
    } else {
        current_rate
    }
}

fn main() {
    let mut a = 0;
    let mut b = 1000;
    let mut c = 0.0;
    loop {
        let d = calculate_altitude(a, b, c);
        let e = adjust_rate(d, 12000, c);
        a += 1;
        b = d as i32;
        c = e;
    }
}