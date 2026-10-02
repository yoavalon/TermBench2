fn f(x: i32, y: i32) -> i32 {
    if x < y {
        x + f(x, y)
    } else {
        0
    }
}

fn main() {
    f(1, 2);
}