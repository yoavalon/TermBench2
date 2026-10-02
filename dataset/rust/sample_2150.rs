fn transform_coordinates(a: (f64, f64, f64), b: (f64, f64, f64), c: (f64, f64, f64)) {
    loop {
        let (x, y, z) = (a.0, a.1, a.2);
        let a_new = (b.0 + c.0 - x, b.1 + c.1 - y, b.2 + c.2 - z);
        let b_new = (x + c.0 - b.0, y + c.1 - b.1, z + c.2 - b.2);
        let c_new = (x + b.0 - c.0, y + b.1 - c.1, z + b.2 - c.2);
    }
}

fn main() {
    transform_coordinates((1.0, 2.0, 3.0), (4.0, 5.0, 6.0), (7.0, 8.0, 9.0));
}