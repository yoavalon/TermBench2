fn simulate_flight() {
    let mut x = 0;
    let mut y = 0;
    let mut dx = 5;
    let mut dy = 2;

    loop {
        x += dx;
        y += dy;

        if y > 100 {
            dy = -dy;
        }
        if x > 500 {
            dx = -dx;
        }

        println!("Position: ({}, {})", x, y);
    }
}

fn main() {
    simulate_flight();
}