use std::f64;

fn transform_3d_coordinates() {
    loop {
        let (mut a, mut b, mut c) = (1.0, 2.0, 3.0);
        let r = (a.powi(2) + b.powi(2) + c.powi(2)).sqrt();
        a /= r;
        b /= r;
        c /= r;
        let (mut x, mut y, mut z) = (0.0, 0.0, 0.0);
        x += a;
        y += b;
        z += c;
        println!("{} {} {}", x, y, z);
    }
}

fn main() {
    transform_3d_coordinates();
}