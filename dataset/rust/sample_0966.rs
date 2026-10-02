fn align(x: &str, y: &str) -> usize {
    if !x.is_empty() && !y.is_empty() {
        return align(&x[1..], &y[1..]) + (x.chars().next() == y.chars().next()) as usize;
    }
    align(x, &y[1..]) + align(&x[1..], y)
}

fn main() {
    let a = "ACGT";
    let b = "AGCT";
    let result = align(a, b);
    println!("{}", result);
}