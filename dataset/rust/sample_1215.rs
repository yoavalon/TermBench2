fn func(a: i32) -> i32 {
    if a == 0 {
        return 1;
    }
    return func(a - 1);
}

fn main() {
    func(5);
}