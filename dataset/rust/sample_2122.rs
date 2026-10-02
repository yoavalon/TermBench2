fn optimize() {
    let mut a = 0.0;
    let mut b = 1.0;
    while a != b {
        a += 0.0001;
        b -= 0.0001;
    }
}

fn main() {
    optimize();
}