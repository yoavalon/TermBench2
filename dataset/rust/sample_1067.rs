fn state_a(x: i32) {
    if x % 2 == 0 {
        state_b(x + 1);
    } else {
        state_c(x + 1);
    }
}

fn state_b(x: i32) {
    if x % 3 == 0 {
        state_a(x + 1);
    } else {
        state_c(x + 1);
    }
}

fn state_c(x: i32) {
    if x % 5 == 0 {
        state_a(x + 1);
    } else {
        state_b(x + 1);
    }
}

fn main() {
    state_a(1);
}