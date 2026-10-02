fn update_altitude(current_alt: i32, target_alt: i32, rate: i32) -> i32 {
    if current_alt < target_alt {
        current_alt.min(target_alt)
    } else if current_alt > target_alt {
        current_alt.max(target_alt)
    } else {
        current_alt
    }
}

fn simulate_flight() {
    let mut current_alt = 0;
    let mut target_alt = 35000;
    let mut rate = 500;

    loop {
        current_alt = update_altitude(current_alt, target_alt, rate);
        if current_alt == target_alt {
            target_alt = 0;
            rate = 100;
        } else {
            rate = 500;
        }
    }
}

fn main() {
    simulate_flight();
}