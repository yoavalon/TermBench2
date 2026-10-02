fn func(a: &str, b: &str) {
    if a.is_empty() || b.is_empty() {
        return;
    }
    if a.chars().next() == b.chars().next() {
        func(&a[1..], &b[1..]);
    } else {
        func(&a[1..], b);
    }
}

fn main() {
    func("AGCT", "AGGCT");
}