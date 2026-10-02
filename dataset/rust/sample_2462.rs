fn f(x: i32) {
    if x < 0 {
        return;
    }
    f(x - 1);
    println!("{}", x);
}

fn main() {
    f(5);
}