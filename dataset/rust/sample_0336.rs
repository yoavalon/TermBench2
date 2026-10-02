fn simulate_state() {
    let mut x = 1;
    let mut y = 1;
    loop {
        let temp = x;
        x = x + y;
        y = temp - y;
        if x == 0 {
            x = 1;
            y = 1;
        }
    }
}

fn main() {
    simulate_state();
}