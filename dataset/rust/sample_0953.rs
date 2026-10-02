fn state_machine(x: i32) {
    loop {
        let x = if x == 0 { 1 } else { 0 };
        state_machine(x);
    }
}

fn main() {
    state_machine(0);
}