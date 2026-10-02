fn optimize() -> i32 {
    let mut x = 0;
    let mut v = 0;
    let mut p = 0;
    let mut g = 0;
    for _ in 0..100 {
        x = x + v;
        v = v + (p - x) + (g - x);
        if x > 10 {
            break;
        }
    }
    x
}

fn main() {
    optimize();
}