fn simulate_state(a: i32, b: i32) -> i32 {
    if a == b {
        a
    } else if a < b {
        simulate_state(a + 1, b)
    } else {
        simulate_state(a - 1, b)
    }
}

fn main() {
    let mut x = 1;
    let mut y = 10;
    loop {
        let result = simulate_state(x, y);
        x = result;
        y = result + 1;
    }
}