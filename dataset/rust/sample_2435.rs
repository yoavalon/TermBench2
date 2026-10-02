fn f(x: usize) -> usize {
    let (mut a, mut b, mut c) = (0, 1, 1);
    for _ in 0..x {
        let temp = a + b + c;
        a = b;
        b = c;
        c = temp;
    }
    a
}

fn main() {
    f(10);
}