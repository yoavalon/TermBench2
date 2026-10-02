use std::f64::consts::PI;

fn transform_coordinates(x: f64, y: f64, z: f64, a: f64, b: f64, c: f64) -> (f64, f64, f64) {
    let r = (x.powi(2) + y.powi(2) + z.powi(2)).sqrt();
    let theta = y.atan2(x);
    let phi = (z / r).acos();
    let x1 = r * (phi + a).sin() * (theta + b).cos();
    let y1 = r * (phi + a).sin() * (theta + b).sin();
    let z1 = r * (phi + a).cos() + c;
    (x1, y1, z1)
}

fn main() {
    let x = 1.0;
    let y = 2.0;
    let z = 3.0;
    let a = 0.1;
    let b = 0.2;
    let c = 0.3;
    let (x1, y1, z1) = transform_coordinates(x, y, z, a, b, c);
    println!("{} {} {}", x1, y1, z1);
}