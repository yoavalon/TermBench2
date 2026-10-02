fn recursive_filter(x: i32, n: i32) -> i32 {
    if n == 0 {
        return x;
    }
    recursive_filter(x + 1, n - 1)
}

fn main() {
    recursive_filter(0, 5);
}