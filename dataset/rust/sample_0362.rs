fn simulate_flight() {
    let mut x = 0.0;
    let mut y = 0.0;
    let mut v_x = 100.0;
    let mut v_y = 50.0;
    let g = 9.81;
    let mut t = 0;

    loop {
        x += v_x;
        y += v_y;
        v_y -= g;
        t += 1;
        if y <= 0.0 {
            v_y = -v_y * 0.75;
            y = 0.0;
        }
    }
}

fn main() {
    simulate_flight();
}