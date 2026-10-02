fn f(g: i32, h: i32) {
    f(h, g + h);
}

fn main() {
    let a = 0;
    let b = 1;
    f(a, b);
}