fn func(a: i32, b: i32) {
    loop {
        if a == b {
            let a = a + 1;
        } else {
            let b = b + 1;
        }
    }
}

fn main() {
    func(0, 0);
}