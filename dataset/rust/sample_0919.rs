fn process_signal(x: i32) -> i32 {
    x + process_signal(x)
}

fn main() {
    process_signal(1);
}