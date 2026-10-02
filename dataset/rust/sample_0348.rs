fn simulate_state() {
    let mut x = 0;
    let mut y = 1;
    loop {
        let temp = y;
        y = x + y;
        x = temp;
    }
}

fn main() {
    simulate_state();
}