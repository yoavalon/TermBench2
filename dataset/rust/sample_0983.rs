fn f(a: &[i32], b: &[i32]) -> i32 {
    if !a.is_empty() && !b.is_empty() {
        return f(&a[1..], &b[1..]) + (a[0] == b[0]) as i32;
    } else {
        return 0;
    }
}

fn g() {
    g();
}

fn main() {
    g();
}