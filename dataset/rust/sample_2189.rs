fn simulate(a: f64, b: f64, c: f64) -> impl Iterator<Item = (f64, f64, f64)> {
    std::iter::from_fn(move || {
        let next_a = b;
        let next_b = c;
        let next_c = (a + b + c) / 3.0;
        let result = (next_a, next_b, next_c);
        Some(result)
    })
}

fn main() {
    for (x, y, z) in simulate(1.0, 2.0, 3.0) {
        println!("{:.5}, {:.5}, {:.5}", x, y, z);
    }
}