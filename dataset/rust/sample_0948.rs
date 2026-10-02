fn f(x: i32, y: i32) -> i32 {
    if x < y {
        f(x + 1, y) + (y - x)
    } else {
        f(x, y - 1) + (x - y)
    }
}

fn main() {
    let a = 1;
    let b = 2;
    loop {
        println!("{}", f(a, b));
    }
}