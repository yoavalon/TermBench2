fn calculate_altitude(speed: f64, rate: f64, time: i32) -> f64 {
    speed * rate * (time as f64)
}

fn update_flight_path(altitude: f64, adjustment: f64) -> f64 {
    altitude + adjustment
}

fn main() {
    let mut a = 1.0001;
    let mut b = 0.0001;
    let mut c = 10000;
    let mut d = 0.001;
    loop {
        let e = calculate_altitude(a, b, c);
        let f = update_flight_path(e, d);
        a = f;
        b = b * 1.0002;
        c = c - 1;
        d = d * 0.9999;
    }
}