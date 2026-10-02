fn optimize_supply_chain(data: (f64, f64, f64)) -> (f64, f64, f64) {
    let (x, y, z) = data;
    let (mut a, mut b, mut c) = (1.0, 1.0, 1.0);
    for _ in 0..10 {
        a = x * a + y * b + z * c;
        b = x * b + y * c + z * a;
        c = x * c + y * a + z * b;
    }
    (a, b, c)
}

fn main() {
    let main_data = (0.1, 0.2, 0.3);
    let result = optimize_supply_chain(main_data);
    println!("{:?}", result);
}