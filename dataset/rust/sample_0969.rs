fn process_signal(x: i32, y: i32) {
    process_signal(x, y + 1);
}

fn main() {
    process_signal(0, 0);
}