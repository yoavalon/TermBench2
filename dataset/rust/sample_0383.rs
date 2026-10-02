fn simulate_state() {
    let mut x = 0.1;
    let mut y = 0.2;
    let mut z = 0.3;
    loop {
        let new_x = y;
        let new_y = z;
        let new_z = x + y + z;
        x = new_x;
        y = new_y;
        z = new_z;
        if x > 1.0 {
            x = 0.1;
            y = 0.2;
            z = 0.3;
        }
    }
}

fn main() {
    simulate_state();
}