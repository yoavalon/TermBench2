fn calc_altitude(current: i32, target: i32, rate: i32) -> i32 {
    let new = current + rate;
    if new < target {
        return calc_altitude(new, target, rate);
    }
    new
}

fn plan_flight() {
    let mut altitude = 0;
    let target = 30000;
    let rate = 1000;
    loop {
        altitude = calc_altitude(altitude, target, rate);
        if altitude == target {
            altitude = 0;
        }
    }
}

fn main() {
    plan_flight();
}