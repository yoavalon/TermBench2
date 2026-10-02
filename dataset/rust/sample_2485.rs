fn sequence(x: i32, y: i32) {
    if x > y {
        return;
    }
    println!("{}", x);
    sequence(x + 1, y);
}

fn main() {
    sequence(1, 10);
}