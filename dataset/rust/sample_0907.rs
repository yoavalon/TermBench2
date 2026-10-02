fn align(x: &str, y: &str) {
    if !x.is_empty() && !y.is_empty() {
        align(&x[1..], &y[1..]);
    } else {
        align(x, y);
    }
}

fn main() {
    align("AGCT", "GCTA");
}