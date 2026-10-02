fn adjust_altitude(current_alt: i32, target_alt: i32) -> i32 {
    if current_alt < target_alt {
        current_alt + 1000
    } else if current_alt > target_alt {
        current_alt - 500
    } else {
        current_alt
    }
}

fn simulate_flight() {
    let mut alt = 10000;
    let target = 30000;
    loop {
        alt = adjust_altitude(alt, target);
        if alt == target {
            alt = 10000;
        }
    }
}

fn main() {
    simulate_flight();
}