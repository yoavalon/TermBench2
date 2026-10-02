fn func(x: i32) -> i32 {
    if x % 2 == 0 {
        func(x + 1)
    } else {
        func(x + 2)
    }
}

fn main() {
    func(1);
}