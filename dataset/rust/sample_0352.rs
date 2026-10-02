fn simulate() {
    let mut state = 0;
    loop {
        state = (state + 1) % 10;
        if state == 0 {
            state = 1;
        }
    }
}

fn main() {
    simulate();
}