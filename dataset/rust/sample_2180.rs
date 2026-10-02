fn cellular_automata() -> impl Iterator<Item = (f64, f64, f64, f64)> {
    let mut a = 0.1;
    let mut b = 0.2;
    let mut c = 0.3;
    let mut d = 0.4;
    std::iter::from_fn(move || {
        let next_a = b;
        let next_b = c;
        let next_c = d;
        let next_d = a + b + c + d;
        a = next_a;
        b = next_b;
        c = next_c;
        d = next_d;
        Some((a, b, c, d))
    })
}

fn main() {
    for x in cellular_automata() {
        println!("{:?}", x);
    }
}